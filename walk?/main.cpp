//
//  main.cpp
//  walk?
//
//  Created by J. Riley Hill on 13-07-03.
//  Copyright (c) 2013 Mortfell Oktorium. All rights reserved.
//

#include <iostream>
#include"guy.h"
using namespace std;

int main( int argc, char** args)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        return 1;
    }
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_SWSURFACE );
    if ( screen == NULL )
    {
        return 1;
    }
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 256) == -1)
    {
        cout << "sound town failed to boogey down" << endl;
        return 1;
    }
    
    
    // load files
    background = load_image("background.bmp");
    theguy = load_image("guy.bmp");
    footstep = Mix_LoadWAV("foot.wav");
    duck_sound = Mix_LoadWAV("duck.wav");
    song = Mix_LoadMUS("boomtownforks.wav");
    
        if (footstep == NULL)
    {
        cout << "sound fail" << endl;
        return 1;
    }
    Guy myguy(70, HEIGHT-theguy->h);
    
                 
    if ( theguy == NULL )
    {
        cout << "woops" << endl;
    }
    SDL_EnableKeyRepeat(5, 5);
    
    
    
    // do things
    Mix_PlayMusic(song, -1);
    while( quit == false)
    {
        if(SDL_PollEvent(&event))
           {
               
               myguy.handle_events();
               
                   
               if (event.type == SDL_QUIT) 
               {
                   quit = true;
               }
               
           }
        
        apply_surface(0, 0 , background, screen, NULL);
        myguy.show();
        
        SDL_Flip(screen);
    }     
        
    // started from the bottom now we here!r
    Mix_HaltMusic();
    
    Mix_FreeChunk(footstep);
    Mix_FreeChunk(duck_sound);
    Mix_FreeMusic(song);
    
    
    SDL_FreeSurface(background);
    SDL_FreeSurface(theguy);
    
    Mix_CloseAudio();
    SDL_Quit();
    
    return 0;
    
    

}