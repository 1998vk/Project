#ifndef Pacman_H
#define Pacman_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <windows.h>

class Pacman : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Pacman(QObject *parent = 0);
    ~Pacman();

signals:

public slots:
    void slotGameTimer();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int steps;
    int rotation;
    int countForSteps;  // Счётчик для отсчета тиков таймера, когда мы нажимали на кнопки
};

#endif // Pacman_H