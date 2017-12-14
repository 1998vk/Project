#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <windows.h>
#include "level.h"
#include "widget.h"

class Pacman : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Pacman(QObject *parent = 0);
    ~Pacman();

signals:

public slots:
    void slotGameTimer(Level *level);
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int steps;
    int rotation;
    int countForSteps;  // Счётчик для отсчета тиков таймера, когда мы нажимали на кнопки
};
