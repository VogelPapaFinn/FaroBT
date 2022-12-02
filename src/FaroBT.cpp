#include "../include/FaroBT.h"

FaroBT::FaroBT(QWidget *parent) : 
    QMainWindow(parent)
{
    ui_.setupUi(this);

    // Show Users Page
    findChild<QStackedWidget*>("stacked_sites")->setCurrentIndex(2);

    // Send GUIBuild-Event to sidebar
    // Needs to be done so the sidebar can be collapsed and expanded
    QCoreApplication::postEvent(ui_.sidebar, new GUIBuild());
}

FaroBT::~FaroBT()
{}
