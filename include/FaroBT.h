#pragma once

#include "GUIBuild.h"
#include "UserSite.h"

#include <QtWidgets/QMainWindow>
#include "ui_FaroBT.h"

class FaroBT : public QMainWindow
{
    Q_OBJECT

public:
    FaroBT(QWidget *parent = nullptr);
    ~FaroBT();

private:
    Ui::FaroBTClass ui_;
};