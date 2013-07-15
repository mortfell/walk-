//
//  guy.h
//  walk?
//
//  Created by J. Riley Hill on 13-07-03.
//  Copyright (c) 2013 Mortfell Oktorium. All rights reserved.
//

#include"globals.h"


#ifndef walk__guy_h
#define walk__guy_h
class Guy
{
public:
    Guy(int init_x, int init_y);
    void handle_events();
    void show();
private:
    bool lookin;
    bool is_duck;
    int count;
    int x;
    int y;
    SDL_Rect space;
    SDL_Rect clips[4];
    const int walk1;
    const int walk2;
    const int mouseover;
    const int duck;
};
#endif
