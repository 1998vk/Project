#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QGraphicsScene>
//#include <QShortcut>
#include <QTimer>
#include "pacman.h"


namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

private:
    Ui::Widget *ui;
    createLevel(Widget *w);
public:
    Pacman *pacman;
    void canMove(Widget *w);
   // Ghost *ghost;
    QTimer *timer;
    QGraphicsScene *scene;
    char map[22][20];
    bool goodies[22][20];
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void slotCheckDirections(Widget *w);

};
#endif // WIDGET_H
