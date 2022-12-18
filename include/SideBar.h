#pragma once

#include "GUIBuild.h"

#include "dep/spdlog/spdlog.h"

#include <QtWidgets/qapplication.h>
#include <QtWidgets/qframe.h>
#include <QtWidgets/qpushbutton.h>
#include <QtCore/qpropertyanimation.h>
#include <QtWidgets/qwidget.h>

class SideBar : public QFrame
{
public:
	SideBar(QWidget* parent = nullptr);

	void customEvent(QEvent* event) override;

public slots:
	void toggleSideBar();

private:
	QPushButton* toggle_menu_;
};

