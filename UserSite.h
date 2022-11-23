#pragma once

#include "DefaultTableModel.h"
#include "GUIBuild.h"
#include "SqlConnection.h"

#include <qboxlayout.h>
#include <qfile.h>
#include <qframe.h>
#include <qgraphicseffect.h>
#include <qheaderview.h>
#include <qrgb.h>
#include <quiloader.h>
#include <qscrollarea.h>
#include <qsqltablemodel.h>
#include <qtableview.h>
#include <qwidget.h>

class UserSite : public QWidget
{
public:
	UserSite(QWidget* parent = nullptr);

	void resizeEvent(QResizeEvent* event);

private:
	QWidget *widget_;
	QVBoxLayout *layout_;
	QSpacerItem* spacer_;
	QGraphicsDropShadowEffect* drop_shadow_effect_;

	QSqlDatabase* db_;
	QSqlTableModel* sql_model_;
	QHeaderView* tv_header_;
	QTableView* table_view_;
};

