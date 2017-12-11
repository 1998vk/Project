#pragma once

class Level
{
public :
    static const int width = 32;
    static const int height = 28;
    int createflag;
    char map[width][height];
private:
    void create ();
};
