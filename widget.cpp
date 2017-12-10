#include "pacman.h"
#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(900,600);          // Задаем размеры окна
    this->setFixedSize(900,600);    // Фиксируем размеры окна

    scene = new QGraphicsScene();   // Инициализируем графическую сцену
    pacman = new Pacman();

    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену

    //ui->graphicsView->setRenderHint(QPainter::Antialiasing); //Подключаем сглаживание (в этой игре вообще не нужно, но чтоб не искать, если вдруг что)
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Отключаем ползунки по вертикали и горизонтали

    scene->setSceneRect(-450,-300,900,600); // Устанавливаем область графической сцены
    scene->setBackgroundBrush(Qt::black);

    scene->addLine(-250,0,250,0,QPen(Qt::white));   //Линия через центр
    scene->addLine(0,-250,0,250,QPen(Qt::white));

    scene->addLine(-320,-260, 320,-260, QPen(Qt::white));
    scene->addLine(-320, 260, 320, 260, QPen(Qt::white));
    scene->addLine(-320,-260,-320, 260, QPen(Qt::white));
    scene->addLine( 320,-260, 320, 260, QPen(Qt::white));

    scene->addItem(pacman);
    pacman->setPos(0,0);

    /* Инициализируем таймер и вызываем слот обработки сигнала таймера
     * 20 раз в секунду.
     * */
    timer = new QTimer();
    connect(timer, &QTimer::timeout, pacman, &Pacman::slotGameTimer);
    timer->start(1000 / 50);
}

Widget::~Widget()
{
    delete ui;
}
