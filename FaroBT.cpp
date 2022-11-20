#include "FaroBT.h"

FaroBT::FaroBT(QWidget *parent) : 
    QMainWindow(parent)
{
    ui_.setupUi(this);



    // Send GUIBuild-Event to sidebar
    // Needs to be done so the sidebar can be collapsed and expanded
    QCoreApplication::postEvent(ui_.sidebar, new FGUIBuild());

    FUserSite* tmp = findChild<FUserSite*>("user_site");
    tmp->addEntry();
}

FaroBT::~FaroBT()
{}
