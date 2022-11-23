#include "FaroBT.h"
#include "easylogging++.h"

#include <QtWidgets/QApplication>

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FaroBT w;
    w.showMaximized();
    w.show();

    el::Configurations defaultConf;
    defaultConf.setToDefault();
    defaultConf.set(el::Level::Info, el::ConfigurationType::Format, "%datetime %level %msg");
    defaultConf.setGlobally(el::ConfigurationType::Format, "%date %msg");
    el::Loggers::reconfigureLogger("default", defaultConf);

    return a.exec();
}
