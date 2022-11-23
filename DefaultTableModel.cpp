#include "DefaultTableModel.h"

namespace fbt
{
	QModelIndex DefaultTableModel::index(int row, int column, const QModelIndex& parent) const
	{
		return QModelIndex();
	}

	QModelIndex DefaultTableModel::parent(const QModelIndex& index) const
	{
		return QModelIndex();
	}

	int DefaultTableModel::rowCount(const QModelIndex& parent) const
	{
		return 0;
	}

	int DefaultTableModel::columnCount(const QModelIndex& parent) const
	{
		return 1;
	}

	QVariant DefaultTableModel::data(const QModelIndex& index, int role) const
	{
		return QVariant();
	}
}