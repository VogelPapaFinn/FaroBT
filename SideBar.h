#pragma once

#include "FGUIBuild.h"

#include <qapplication.h>
#include <qframe.h>
#include <qpushbutton.h>
#include <qpropertyanimation.h>
#include <qwidget.h>

class SideBar : public QFrame
{
public:
	SideBar(QWidget* parent = nullptr);

	void customEvent(QEvent* event);

public slots:
	void toggleSideBar();

private:
	QPushButton* toggle_menu_;
};

