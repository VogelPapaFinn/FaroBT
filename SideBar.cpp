#include "SideBar.h"

SideBar::SideBar(QWidget* parent) :
	QFrame(parent),
	toggle_menu_(nullptr)
{
}

void SideBar::customEvent(QEvent* event)
{
	if (event->type() == GUIBuildEvent)
	{
		// Find toggle_menu
		toggle_menu_ = findChild<QPushButton*>("toggle_menu");

		// Connect
		connect(toggle_menu_, &QPushButton::clicked, this, &SideBar::toggleSideBar);
	}
}



void SideBar::toggleSideBar()
{
	if (maximumWidth() == 155)
	{
		// Animation for minimumWidth
		QPropertyAnimation* slide_open_min = new QPropertyAnimation(this, "minimumWidth");
		slide_open_min->setDuration(200);
		slide_open_min->setStartValue(155);
		slide_open_min->setEndValue(55);
		slide_open_min->setKeyValueAt(0.4, 100);
		slide_open_min->start();

		// Animation for maximumWidth
		QPropertyAnimation* slide_open_max = new QPropertyAnimation(this, "maximumWidth");
		slide_open_max->setDuration(200);
		slide_open_max->setStartValue(155);
		slide_open_max->setEndValue(55);
		slide_open_max->setKeyValueAt(0.4, 100);
		slide_open_max->start();
	}
	else
	{
		// Animation for maximumWidth
		QPropertyAnimation* slide_open_max = new QPropertyAnimation(this, "maximumWidth");
		slide_open_max->setDuration(200);
		slide_open_max->setStartValue(55);
		slide_open_max->setEndValue(155);
		slide_open_max->setKeyValueAt(0.4, 100);
		slide_open_max->start();

		// Animation for minimumWidth
		QPropertyAnimation* slide_open_min = new QPropertyAnimation(this, "minimumWidth");
		slide_open_min->setDuration(200);
		slide_open_min->setStartValue(55);
		slide_open_min->setEndValue(155);
		slide_open_min->setKeyValueAt(0.4, 100);
		slide_open_min->start();
	}
}