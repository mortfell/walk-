//
//  globals.h
//  walk?
//
//  Created by J. Riley Hill on 13-07-03.
//  Copyright (c) 2013 Mortfell Oktorium. All rights reserved.
//

#include"SDL/SDL.h"
#include"SDL_Mixer/SDL_Mixer.h"

#ifndef ss
#define ss SDL_Surface
#endif



#ifndef MouseEvents_globals_h
#define MouseEvents_globals_h
//functions
void apply_surface( int x, int y, ss* source, ss* dest, SDL_Rect* clip);
ss* load_image(std::string filename);


//SCREEN ATTRIBUTES
const int WIDTH = 640;
const int HEIGHT = 480;
const int BPP = 32;
// button states
const int CLIP_MOUSEOVER = 0;
const int CLIP_MOUSEOUT = 1;
const int CLIP_MOUSEDOWN = 2;
const int CLIP_MOUSEUP = 3;
// surfaces
extern SDL_Surface* theguy;
extern SDL_Surface* screen;
extern SDL_Surface* background;
// mixer sounds
extern Mix_Chunk* footstep;
extern Mix_Chunk* duck_sound;
extern Mix_Music* song;


extern bool quit;


extern SDL_Event event;
//extern SDL_Rect clips[4];
#endif

