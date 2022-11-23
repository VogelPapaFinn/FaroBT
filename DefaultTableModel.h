#pragma once

#include <qabstractitemmodel.h>

namespace fbt
{
	// Has only one column; Used to display a basic QTableView if the source model is broken.
	class DefaultTableModel : public QAbstractItemModel
	{
	public:
		QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
		QModelIndex parent(const QModelIndex& index) const override;
		int rowCount(const QModelIndex& parent = QModelIndex()) const override;
		int columnCount(const QModelIndex& parent = QModelIndex()) const override;
		QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	};
}

