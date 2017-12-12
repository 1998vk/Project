#include "widget.h"
#include<iostream>
#include <stdio.h>
#include <QApplication>
#include <QLineEdit>
#include "pacman.h"
#include <windows.h>

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.timer->start(1000 / 50); // Инициализируем таймер и вызываем слот обработки сигнала таймера20 раз в секунду

    return a.exec();
}
