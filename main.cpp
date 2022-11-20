#include "FaroBT.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FaroBT w;
    w.showMaximized();
    w.show();
    return a.exec();
}
