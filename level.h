#pragma once
#include "widget.h"

class Level
{
public :
    Level();
    static const int width = 32;
    static const int height = 28;
    static const int createflag = 1; //Это временный костыль до появления меню
    char map[width][height];
    void create (Widget *w);
};
