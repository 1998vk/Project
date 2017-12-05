#include "pacman.h"
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(600,600);          // Задаем размеры окна
    this->setFixedSize(600,600);    // Фиксируем размеры окна

    scene = new QGraphicsScene();   // Инициализируем графическую сцену
    pacman = new Pacman();

    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView

    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(-250,-250,500,500); // Устанавливаем область графической сцены
    scene->setBackgroundBrush(Qt::black);

    scene->addLine(-250,0,250,0,QPen(Qt::white));   //Линия через центр
    scene->addLine(0,-250,0,250,QPen(Qt::white));

    scene->addLine(-250,-250, 250,-250, QPen(Qt::white));
    scene->addLine(-250, 250, 250, 250, QPen(Qt::white));
    scene->addLine(-250,-250,-250, 250, QPen(Qt::white));
    scene->addLine( 250,-250, 250, 250, QPen(Qt::white));

    scene->addItem(pacman);
    pacman->setPos(0,0);

    /* Инициализируем таймер и вызываем слот обработки сигнала таймера
     * 20 раз в секунду.
     * Управляя скоростью отсчётов, соответственно управляем скоростью
     * изменения состояния графической сцены
     * */
    timer = new QTimer();
    connect(timer, &QTimer::timeout, pacman, &Pacman::slotGameTimer);
    timer->start(1000 / 50);
}

Widget::~Widget()
{
    delete ui;
}
