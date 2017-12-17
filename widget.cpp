#include "ui_widget.h"
#include "widget.h"
#include <windows.h>
#include <math.h>
#include "pacman.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //ui->setupUi(this);
    this->resize(900,600);
    this->setFixedSize(900,600);
    scene = new QGraphicsScene();


    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(-450,-300,900,600);
    scene->setBackgroundBrush(Qt::black);
    pacman = new Pacman();
    scene->addItem(pacman);
    createLevel(this);
    timer = new QTimer();
    //connect(timer, &QTimer::timeout, pacman, &Pacman::slotGameTimer(level));
    //canMove(this);
   // connect(timer, &QTimer::timeout, this, slotCheckDirections(this));
//    connect(timer, &QTimer::timeout, pacman, pacman->slotGameTimer());

}

void canMove(Widget *w)
{
    if(w->map[static_cast<int>(((w->pacman->x() - fmod(w->pacman->x(), 20)) + 320 + 10) / 20)][static_cast<int>(w->pacman->y())] = '1')
    {
        w->pacman->pacmanDirection[2] = false;
    }
    if(w->map[static_cast<int>(((w->pacman->x() - fmod(w->pacman->x(), 20)) + 320 - 10) / 20)][static_cast<int>(w->pacman->y())] = '1')
    {
        w->pacman->pacmanDirection[0] = false;
    }

    if(w->map[static_cast<int>(w->pacman->x())][static_cast<int>(((w->pacman->y() - fmod(w->pacman->y(), 20)) + 260 - 10) / 20)] = '1')
    {
        w->pacman->pacmanDirection[1] = false;
    }
    if(w->map[static_cast<int>(w->pacman->x())][static_cast<int>(((w->pacman->y() - fmod(w->pacman->y(), 20)) + 260 + 10) / 20)] = '1')
    {
        w->pacman->pacmanDirection[3] = false;
    }
}

void slotCheckDirections(Widget *w)
{
    canMove(w);
}

void createLevel(Widget *w)
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
           w->goodies[i][j] = false;
           w->map[i][j] = a[i][j];
           if(w->map[i][j] == '1')
               w->scene->addRect(-320 + j * 20, -260 + i * 20, 19, 19, QPen(Qt::darkBlue), QBrush(Qt::blue));
               else if (w->map[i][j] == '0')
                    {
                       w->scene->addEllipse(-312 + j * 20, -252 + i * 20, 4, 4, QPen(Qt::yellow), QBrush(Qt::white));
                       w->goodies[i][j] = true;
                    }
                        else if (w->map[i][j] == 'P')
                           w->pacman->setPos(-310 + j * 20, -250 + i * 20);
         }
}

Widget::~Widget()
{
    delete ui;
}
