#include "widget.h"
#include<iostream>
#include <stdio.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
