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
    }
    if(rotation == 1) // TODO: сделать тру положение рта не только в правом положении
    {
        if(steps == 0)
        {
           painter->setPen(QPen(Qt::black, 2));
           painter->setBrush(Qt::black);
           painter->drawPie(-10,-10, 20, 20, 60 * 16, 60 * 16);
        }
        if(steps == 1)
        {
           painter->setPen(QPen(Qt::black, 2));
           painter->setBrush(Qt::black);
           painter->drawPie(-10,-10, 20, 20, 75 * 16, 30 * 16);
        }
    }
    if(rotation == 2)
    {
        if(steps == 0)
        {
           painter->setPen(QPen(Qt::black, 2));
           painter->setBrush(Qt::black);
           painter->drawPie(-10,-10, 20, 20, 150 * 16, 60 * 16);
        }
        if(steps == 1)
        {
           painter->setPen(QPen(Qt::black, 2));
           painter->setBrush(Qt::black);
           painter->drawPie(-10,-10, 20, 20, 165 * 16, 30 * 16);
        }
    }
    if(rotation == 3)
    {
        if(steps == 0)
        {
           painter->setPen(QPen(Qt::black, 2));
           painter->setBrush(Qt::black);
           painter->drawPie(-10,-10, 20, 20, 240 * 16, 60 * 16);
        }
        if(steps == 1)
        {
           painter->setPen(QPen(Qt::black, 2));
           painter->setBrush(Qt::black);
           painter->drawPie(-10,-10, 20, 20, 255 * 16, 30 * 16);
        }
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Pacman::slotGameTimer()
{
    // Проверяем, нажата ли была какая-либо из кнопок управления объектом.

    if(GetAsyncKeyState(VK_LEFT) ||
       GetAsyncKeyState(VK_RIGHT) ||
       GetAsyncKeyState(VK_UP) ||
       GetAsyncKeyState(VK_DOWN))
    {
        if(GetAsyncKeyState(VK_LEFT)){
            setPos(mapToParent(-2, 0));
            rotation = 2;
        }
        if(GetAsyncKeyState(VK_RIGHT)){
            setPos(mapToParent(2, 0));
            rotation = 0;
        }
        if(GetAsyncKeyState(VK_UP)){
            setPos(mapToParent(0, -2));
            rotation = 1;
        }
        if(GetAsyncKeyState(VK_DOWN)){
            setPos(mapToParent(0, 2));
            rotation = 3;
        }

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
    }

    if(this->x() - 10 < -250){
        this->setX(-240);
    }
    if(this->x() + 10 > 250){
        this->setX(240);
    }

    if(this->y() - 10 < -250){
        this->setY(-240);
    }
    if(this->y() + 10 > 250){
        this->setY(240);
    }
}

