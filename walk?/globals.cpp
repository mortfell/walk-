//
//  globals.cpp
//  walk?
//
//  Created by J. Riley Hill on 13-07-03.
//  Copyright (c) 2013 Mortfell Oktorium. All rights reserved.
//

#include <iostream>
#include "globals.h"
SDL_Surface* theguy;
SDL_Surface* screen;
SDL_Surface* background;

Mix_Chunk* footstep = NULL;
Mix_Chunk* duck_sound = NULL;
Mix_Music* song = NULL;

SDL_Event event;

bool quit = false;

//SDL_Rect clips[4];

// important global functions
ss* load_image(std::string filename)
{
    ss* temp = NULL;
    ss* opt = NULL;
    
    temp = SDL_LoadBMP(filename.c_str() );
    if ( temp == NULL )
    {
        return NULL;
    }
    
    opt = SDL_DisplayFormat(temp);
    Uint32 key = SDL_MapRGB(opt->format, 0, 0xff, 0xff);
    SDL_SetColorKey(opt, SDL_SRCCOLORKEY, key);
    
    SDL_FreeSurface(temp);
    return opt;
}

void apply_surface( int x, int y, ss* source, ss* dest, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, clip, dest, &offset);
}