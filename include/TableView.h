#pragma once

#include <spdlog/spdlog.h>

#include <qevent.h>
#include <qtableview.h>

class TableView : public QTableView
{
	Q_OBJECT

	public:
		TableView(QWidget* parent = nullptr);

	private:
		void mouseMoveEvent(QMouseEvent* event);
};