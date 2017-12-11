#include "Pacman.h"

Pacman::Pacman(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    rotation = 0;
    steps = 0;
    countForSteps = 0;
}

Pacman::~Pacman()
{

}

QRectF Pacman::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::yellow, 2));
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(-10, -10, 20, 20);

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
           painter->drawPie(-15, -10, 25, 20, -30 * 16, 60 * 16);
        }
        if(steps == 1)
        {
           painter->setPen(QPen(Qt::black, 2));
           painter->setBrush(Qt::black);
           painter->drawPie(-15,-10, 25, 20, -15 * 16, 30 * 16);
        }
    Q_UNUSED(option);
    Q_UNUSED(widget);
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
        //И после этого(!) двигаем туда, куда он смотрит теперь

        if(2 == rotation)
            setPos(mapToParent(-2, 0));
        if(0 == rotation)
            setPos(mapToParent(2, 0));
        if(1 == rotation)
            setPos(mapToParent(0, -2));
        if(2 == rotation)
            setPos(mapToParent(0, 2));

        countForSteps++;
        if(countForSteps == 4){
            steps = 2;
            update(QRectF(-10,-10,20,20));
        } else if (countForSteps == 8){
            steps = 1;
            update(QRectF(-10,-10,20,20));
        } else if (countForSteps == 12){
            steps = 0;
            update(QRectF(-10,-10,20,20));
        } else if (countForSteps == 16) {
            steps = 1;
            update(QRectF(-10,-10,20,20));
            countForSteps = 0;
        }

    if(this->x() - 10 < -320){
        this->setX(-310);
    }
    if(this->x() + 10 > 320){
        this->setX(310);
    }

    if(this->y() - 10 < -260){
        this->setY(-250);
    }
    if(this->y() + 10 > 260){
        this->setY(250);
    }
}
