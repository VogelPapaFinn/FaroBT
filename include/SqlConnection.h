#pragma once
#include <vector>

#include <spdlog/spdlog.h>

#include <QtCore/QStringList>
#include <QtSql/qsqldatabase.h>

namespace fbt
{
	class SqlConnection
	{
	public:
		static std::shared_ptr<QSqlDatabase> getInstance();

	private:
		static QSqlDatabase instance_;
	};
}
