#pragma once

#include "ContextMenu.h"
#include "DefaultTableModel.h"
#include "GUIBuild.h"
#include "SqlConnection.h"
#include "TVDelegate.h"

#include <qboxlayout.h>
#include <qfile.h>
#include <qframe.h>
#include <qgraphicseffect.h>
#include <qheaderview.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qmenu.h>
#include <qpushbutton.h>
#include <qrgb.h>
#include <qscrollarea.h>
#include <qsqltablemodel.h>
#include <qtableview.h>
#include <quiloader.h>
#include <qwidget.h>

class UserSite : public QFrame
{
    Q_OBJECT

public:
	UserSite(QWidget* parent = nullptr);

	void customEvent(QEvent* event) override;
	void resizeEvent(QResizeEvent* event) override;

public slots:
    void refreshTableView();
    void searchInTableView();

    void customMenuRequested(QPoint pos);

private:
	std::shared_ptr<QGraphicsDropShadowEffect> drop_shadow_effect_;

	std::shared_ptr<QSqlDatabase> db_;
    std::shared_ptr<QSqlTableModel> sql_model_;
    QHeaderView* tv_header_;
    QTableView* table_view_;
    QLabel* row_counter_;
    QLineEdit* search_line_;
    fbt::ContextMenu* context_menu_;
};