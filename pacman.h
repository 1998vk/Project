#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class Pacman : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int rotation;
    bool pacmanDirection[4];
    explicit Pacman(QObject *parent = 0);
    ~Pacman();
signals:

public slots:
    void slotGameTimer();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter);
private:
    int steps;
    int countForSteps;
};

#endif // PACMAN_H
