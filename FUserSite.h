#pragma once

#include <qboxlayout.h>
#include <qfile.h>
#include <qframe.h>
#include <qgraphicseffect.h>
#include <qrgb.h>
#include <quiloader.h>
#include <qscrollarea.h>
#include <qwidget.h>

// TESTING
#include <qtableview.h>
#include <qheaderview.h>
#include <qsqltablemodel.h>
// TESTING

class FUserSite : public QWidget
{
public:
	FUserSite(QWidget* parent = nullptr);
	void addEntry();

private:
	QWidget *widget_;
	QVBoxLayout *layout_;
	QSpacerItem* spacer_;

	QGraphicsDropShadowEffect* drop_shadow_effect_;
};

