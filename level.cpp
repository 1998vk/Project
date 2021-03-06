#include "level.h"
#include <iostream>
#include <stdio.h>

void Level::create(Widget *w)
{
        char a[22][20] =
        {
            "1111111111111111111",
            "1000000001000000001",
            "1011011101011101101",
            "1000000000000000001",
            "1011010111110101101",
            "1000010001000100001",
            "1111011121211101111",
            "2221012222222101222",
            "1111012112112101111",
            "1222022122212202221",
            "1111012111112101111",
            "2221012222222101222",
            "1111012111112101111",
            "1000000001000000001",
            "1011011101011101101",
            "100100000P000001001",
            "1101010111110101011",
            "1000010001000100001",
            "1011111101011111101",
            "1000000000000000001",
            "1111111111111111111"
        };

     for (int i = 0; i < 22; i++)
         for (int j = 0; j < 20; j++)
         {
            map[i][j] = a[i][j];
            if(map[i][j] == '1')
                w->scene->addRect(-320 + j * 20, -260 + i * 20, 19, 19, QPen(Qt::darkBlue), QBrush(Qt::blue));
                else if (map[i][j] == '0')
                        w->scene->addEllipse(-312 + j * 20, -252 + i * 20, 4, 4, QPen(Qt::yellow), QBrush(Qt::white));
                     else if (map[i][j] == 'P')
                            w->pacman->setPos(-310 + j * 20, -250 + i * 20);
         }
}
