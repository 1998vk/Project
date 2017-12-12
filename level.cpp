#include "level.h"
#include <iostream>
#include <stdio.h>

void Level::create(Widget *w)
{
    if (createflag == 1)
    {       
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
            {
                if(map[i][j] == '1')
                    w->scene->addRect(-320 + j * 20, -260 + i * 20, 20, 20, QPen(Qt::darkBlue), QBrush(Qt::blue));
                else if (map[i][j] == '0')
                        w->scene->addEllipse(-310 + j * 20, -250 + i * 20, 4, 4, QPen(Qt::yellow), QBrush(Qt::white));
                     else if (map[i][j] == 'P')
                          w->pacman->setPos(-310 + j * 20, -250 + i * 20);
            }
    }
}
