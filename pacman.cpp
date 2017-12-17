#include "pacman.h"
#include <windows.h>


Pacman::Pacman(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    rotation = 0;
    steps = 0;
    countForSteps = 0;
    //pacmanDirection = { 1, 0, 1, 0 };
}

Pacman::~Pacman()
{

}

QRectF Pacman::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void Pacman::paint(QPainter *painter/*, const QStyleOptionGraphicsItem *option, QWidget *widget*/)
{
    painter->setPen(QPen(Qt::yellow, 2));
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(-9, -9, 18, 18);

    if(rotation == 0)
    {
        setTransformOriginPoint(transformOriginPoint());
    }
    if(rotation == 1)
    {
        setTransformOriginPoint(transformOriginPoint());
        painter->rotate(-90);
    }
    if(rotation == 2)
    {
        setTransformOriginPoint(transformOriginPoint());
        painter->rotate(180);
    }
    if(rotation == 3)
    {
        setTransformOriginPoint(transformOriginPoint());
        painter->rotate(90);
    }
        if(steps == 0)
        {
           painter->setPen(QPen(Qt::black, 2));
           painter->setBrush(Qt::black);
           painter->drawPie(-15, -9, 25, 18, -30 * 16, 60 * 16);
        }
        if(steps == 1)
        {
           painter->setPen(QPen(Qt::black, 2));
           painter->setBrush(Qt::black);
           painter->drawPie(-15,-9, 25, 18, -15 * 16, 30 * 16);
        }
   // Q_UNUSED(option);
   // Q_UNUSED(widget);
}

void Pacman::slotGameTimer()
{
    // Поворачиваем персонажа, если нажата клавиша

    if(GetAsyncKeyState(VK_LEFT) ||
       GetAsyncKeyState(VK_RIGHT) ||
       GetAsyncKeyState(VK_UP) ||
       GetAsyncKeyState(VK_DOWN))
    {
        if(GetAsyncKeyState(VK_LEFT))
            rotation = 2;
        if(GetAsyncKeyState(VK_RIGHT))
            rotation = 0;
        if(GetAsyncKeyState(VK_UP))
            rotation = 1;
        if(GetAsyncKeyState(VK_DOWN))
            rotation = 3;
    }

    if(2 == rotation && pacmanDirection[2])
        setPos(mapToParent(-2, 0));
    if(0 == rotation && pacmanDirection[0])
        setPos(mapToParent(2, 0));
    if(1 == rotation && pacmanDirection[1])
        setPos(mapToParent(0, -2));
    if(3 == rotation && pacmanDirection[3])
        setPos(mapToParent(0, 2));

    countForSteps++;
    if(countForSteps == 4)
    {
        steps = 2;
        update(boundingRect());
    }
    else if (countForSteps == 8)
    {
         steps = 1;
         update(boundingRect());
    }
    else if (countForSteps == 12)
    {
         steps = 0;
         update(boundingRect());

    }
    else if (countForSteps == 16)
    {
         steps = 1;
         update(boundingRect());
         countForSteps = 0;
    }

}
