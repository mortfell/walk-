//
//  guy.cpp
//  walk?
//
//  Created by J. Riley Hill on 13-07-03.
//  Copyright (c) 2013 Mortfell Oktorium. All rights reserved.
//

#include <iostream>
#include"guy.h"
//#include "globals.h"
using namespace std;

Guy::Guy(int init_x, int init_y)
:mouseover( 0 )
,walk1( 1 )
,walk2(2)
,count( 0 )
,lookin(false)
,duck(3)
,is_duck(false)
{
    // initiaize the different rectangles
    // if you put your mouse over the little guy
    clips[ mouseover ].x = 128;
    clips[ mouseover ].y = 0;
    clips[ mouseover ].w = 64;
    clips[ mouseover ].h = 64;
    // -= -= -= -= 1
    //walking animation one
    clips[ walk1 ].x = 0;
    clips[ walk1 ].y = 0;
    clips[ walk1 ].w = 64;
    clips[ walk1 ].h = 64;
    // -= -= -= -= 2
    // walking animation two
    clips[ walk2 ].x = 64;
    clips[ walk2 ].y = 0;
    clips[ walk2 ].w = 64;
    clips[ walk2 ].h = 64;
    // - - - - - -=====
    // ducking animation
    clips[ duck ].x = 192;
    clips[ duck ].y = 0;
    clips[ duck ].w = 64;
    clips[ duck ].h = 64;
    
    
    space.x = init_x;
    space.y = init_y;
    space.w = theguy->w;
    space.h = theguy->h;
}

void Guy::handle_events()
{
    int mouse_x = 0, mouse_y = 0;
    
    if (event.type == SDL_MOUSEMOTION)
    {
        mouse_x = event.motion.x;
        mouse_y = event.motion.y;
        
        if ( ( mouse_x > space.x ) && (mouse_x < space.x + space.w ) && ( mouse_y > space.y ) && ( mouse_y < space.y + space.h ) )
        {
            lookin = true;
        }
        else lookin = false;
    }
    if (event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_q: quit = true; break;
            case SDLK_ESCAPE: quit = true; break;
                
            case SDLK_LEFT: 
                is_duck = false; 
                space.x-=5;
                
                count+=5; 
                break;
            case SDLK_RIGHT:
                is_duck = false; 
                space.x+=5;
                
                count+=5;
                break;
            case SDLK_DOWN:
                if (is_duck == false)
                    Mix_PlayChannel(-1, duck_sound, 0);
                is_duck = true;
                break;
            
                
            default: is_duck = false; break;
        }
    }
}


void Guy::show()
{
    
    //count++;
    if (count >= 50)
    {
        Mix_PlayChannel(-1,footstep, 0);
        count = 0;
    }   
    if (count < 30 && count > 25)
    {
        Mix_PlayChannel(-1,footstep, 0);
    }
    
    if (is_duck == true)
    {
        apply_surface(space.x, space.y, theguy, screen, &clips[duck]);
        return;
    }

    
    if (lookin == true)
    {
        apply_surface(space.x, space.y, theguy, screen, &clips[ mouseover ]);
        return;
    }

    if (count <= 25)
    {
        apply_surface(space.x, space.y, theguy, screen, &clips[walk1]);
        return;
    }
    else if (count > 25)
    {
        apply_surface(space.x, space.y, theguy, screen, &clips[walk2]);
        return;
    }
       
    apply_surface(space.x, space.y, theguy, screen, &clips[walk1]);
    cout << "uh oh" << endl;
}
