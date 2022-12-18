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

    // Send GUIBuild-Event to usersite
    // Needs to be done so the table view shows data
    QCoreApplication::postEvent(ui_.user_site, new GUIBuild());
}

FaroBT::~FaroBT()
{}
