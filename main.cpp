#include "widget.h"
//#include "ui_widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.timer->start(1000 / 50); // Инициализируем таймер и вызываем слот обработки сигнала таймера20 раз в секунду

    return a.exec();
}
