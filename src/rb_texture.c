//
// Copyright(C) 2007-2014 Samuel Villarreal
// Copyright(C) 2014 Night Dive Studios, Inc.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//    OpenGL Texture
//

#include "rb_texture.h"

extern SDL_Window *windowscreen;

//
// RB_RoundPowerOfTwo
//

int RB_RoundPowerOfTwo(int x)
{
    int mask = 1;
    
    while(mask < 0x40000000)
    {
        if(x == mask || (x & (mask-1)) == x)
        {
            return mask;
        }
        
        mask <<= 1;
    }
    
    return x;
}

//
// RB_SetTexParameters
//

void RB_SetTexParameters(rbTexture_t *rbTexture)
{
    unsigned int clamp;
    unsigned int filter;

    switch(rbTexture->clampMode)
    {
    case TC_CLAMP:
        clamp = GL_CLAMP_TO_EDGE;
        break;

    case TC_CLAMP_BORDER:
        clamp = GL_CLAMP_TO_BORDER;
        break;

    case TC_REPEAT:
        clamp = GL_REPEAT;
        break;

    case TC_MIRRORED:
        clamp = GL_MIRRORED_REPEAT;
        break;

    default:
        return;
    }

    switch(rbTexture->filterMode)
    {
    case TF_LINEAR:
        filter = GL_LINEAR;
        break;

    case TF_NEAREST:
        filter = GL_NEAREST;
        break;

    default:
        return;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, clamp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, clamp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);

    if(GL_EXT_texture_filter_anisotropic)
    {
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, RB_GetMaxAnisotropic());
    }
}

//
// RB_ChangeTexParameters
//

void RB_ChangeTexParameters(rbTexture_t *rbTexture, const texClampMode_t clamp, const texFilterMode_t filter)
{
    if(rbTexture->clampMode == clamp && rbTexture->filterMode == filter)
    {
        return;
    }

    rbTexture->clampMode = clamp;
    rbTexture->filterMode = filter;

    RB_SetTexParameters(rbTexture);
}

//
// RB_BindTexture
//

void RB_BindTexture(rbTexture_t *rbTexture)
{
    dtexture tid;
    dtexture currentTexture;
    int unit;

    if(!rbTexture)
    {
        return;
    }

    tid = rbTexture->texid;
    unit = rbState.currentUnit;
    currentTexture = rbState.textureUnits[unit].currentTexture;

    if(tid == currentTexture)
    {
        return;
    }

    glBindTexture(GL_TEXTURE_2D, tid);

    rbState.textureUnits[unit].currentTexture = tid;
    rbState.numTextureBinds++;
}

//
// RB_UnbindTexture
//

void RB_UnbindTexture(void)
{
    int unit = rbState.currentUnit;
    rbState.textureUnits[unit].currentTexture = 0;

    glBindTexture(GL_TEXTURE_2D, 0);
}

//
// RB_DeleteTexture
//

void RB_DeleteTexture(rbTexture_t *rbTexture)
{
    if(!rbTexture || rbTexture->texid == 0)
    {
        return;
    }

    glDeleteTextures(1, &rbTexture->texid);
    rbTexture->texid = 0;
}

//
// RB_UploadTexture
//

void RB_UploadTexture(rbTexture_t *rbTexture, byte *data, texClampMode_t clamp, texFilterMode_t filter)
{
    rbTexture->clampMode = clamp;
    rbTexture->filterMode = filter;

    glGenTextures(1, &rbTexture->texid);

    if(rbTexture->texid == 0)
    {
        // renderer is not initialized yet
        return;
    }

    glBindTexture(GL_TEXTURE_2D, rbTexture->texid);

    if(data)
    {
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            (rbTexture->colorMode == TCR_RGBA) ? GL_RGBA8 : GL_RGB8,
            rbTexture->width,
            rbTexture->height,
            0,
            (rbTexture->colorMode == TCR_RGBA) ? GL_RGBA : GL_RGB,
            GL_UNSIGNED_BYTE,
            data);
    }
    
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_FALSE);

    RB_SetTexParameters(rbTexture);
    glBindTexture(GL_TEXTURE_2D, 0);
}

//
// RB_UpdateTexture
//

void RB_UpdateTexture(rbTexture_t *rbTexture, byte *data)
{
    if(!rbTexture || rbTexture->texid == 0)
    {
        return;
    }

    if(rbState.textureUnits[rbState.currentUnit].currentTexture != rbTexture->texid)
    {
        return;
    }

    glTexSubImage2D(
        GL_TEXTURE_2D,
        0,
        0,
        0,
        rbTexture->width,
        rbTexture->height,
        (rbTexture->colorMode == TCR_RGBA) ? GL_RGBA : GL_RGB,
        GL_UNSIGNED_BYTE,
        data);
}

//
// RB_BindFrameBuffer
//

void RB_BindFrameBuffer(rbTexture_t *rbTexture)
{
    int unit;
    dtexture currentTexture;

    if(rbTexture->texid == 0)
    {
        glGenTextures(1, &rbTexture->texid);
    }
    
    unit = rbState.currentUnit;
    currentTexture = rbState.textureUnits[unit].currentTexture;
    
    if(rbTexture->texid != currentTexture)
    {
        glBindTexture(GL_TEXTURE_2D, rbTexture->texid);
        rbState.textureUnits[unit].currentTexture = rbTexture->texid;
    }
    
    RB_SetReadBuffer(GL_BACK);
    
	int w;
	int h;
	SDL_GetWindowSize(windowscreen, &w, &h);
	rbTexture->origwidth = w;
	rbTexture->origheight = h;

    rbTexture->width       = rbTexture->origwidth;
    rbTexture->height      = rbTexture->origheight;
    
    glCopyTexImage2D(GL_TEXTURE_2D,
                      0,
                      GL_RGBA8,
                      0,
                      0,
                      rbTexture->origwidth,
                      rbTexture->origheight,
                      0);
    RB_SetTexParameters(rbTexture);
}

//
// RB_BindDepthBuffer
//

void RB_BindDepthBuffer(rbTexture_t *rbTexture)
{
    int unit;
    dtexture currentTexture;

    if(rbTexture->texid == 0)
    {
        glGenTextures(1, &rbTexture->texid);
    }
    
    unit = rbState.currentUnit;
    currentTexture = rbState.textureUnits[unit].currentTexture;
    
    if(rbTexture->texid != currentTexture)
    {
        glBindTexture(GL_TEXTURE_2D, rbTexture->texid);
        rbState.textureUnits[unit].currentTexture = rbTexture->texid;
    }
    
#if 1
	int w;
	int h;
	SDL_GetWindowSize(windowscreen, &w, &h);
	rbTexture->origwidth = w;
	rbTexture->origheight = h;
#else
    rbTexture->origwidth   = SDL_GetWindowSurface(windowscreen)->w;
    rbTexture->origheight  = SDL_GetWindowSurface(windowscreen)->h;
#endif
    rbTexture->width       = rbTexture->origwidth;
    rbTexture->height      = rbTexture->origheight;
    
    glCopyTexImage2D(GL_TEXTURE_2D,
                      0,
                      GL_DEPTH_COMPONENT,
                      0,
                      0,
                      rbTexture->origwidth,
                      rbTexture->origheight,
                      0);

    RB_SetTexParameters(rbTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_NONE);
}
