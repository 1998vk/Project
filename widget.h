#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>

#include <pacman.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget      *ui;
    QGraphicsScene  *scene;
    Pacman          *pacman;
   // Ghost           *ghost;
    QTimer          *timer;       /* Объявляем игровой таймер, благодаря которому
                                  будут производиться изменения положения объекта на сцене
                                  При нажатии клавиш
                                */
};
#endif // WIDGET_H
