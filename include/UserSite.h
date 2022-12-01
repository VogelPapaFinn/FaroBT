#pragma once

#include "DefaultTableModel.h"
#include "TableView.h"
#include "GUIBuild.h"
#include "SqlConnection.h"

#include <QtWidgets/qboxlayout.h>
#include <QtCore/qfile.h>
#include <QtWidgets/qframe.h>
#include <QtWidgets/qgraphicseffect.h>
#include <QtWidgets/qheaderview.h>
#include <QtGui/qrgb.h>
#include <QtUiTools/quiloader.h>
#include <QtWidgets/qscrollarea.h>
#include <QtSql/qsqltablemodel.h>
#include <QtWidgets/qtableview.h>
#include <QtWidgets/qwidget.h>

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