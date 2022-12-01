#include "TableView.h"

TableView::TableView(QWidget* parent) : QTableView(parent)
{
	std::string debug = "";

	SPDLOG_LOG_INFO("main", "fbtTableView constructor called");
}

void TableView::mouseMoveEvent(QMouseEvent* event)
{
	// Handle default events
	QTableView::mouseMoveEvent(event);

	QModelIndex index = indexAt(event->pos());
	model()->setData(index, Qt::BackgroundRole);
}