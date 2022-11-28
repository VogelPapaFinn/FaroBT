#pragma once

#include "GUIBuild.h"

#include <QtWidgets/qapplication.h>
#include <QtWidgets/qframe.h>
#include <QtWidgets/qpushbutton.h>
#include <QtCore/qpropertyanimation.h>
#include <QtWidgets/qwidget.h>

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

