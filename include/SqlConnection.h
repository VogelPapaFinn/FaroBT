#pragma once
#include <vector>

#include <spdlog/spdlog.h>

#include <QtSql/qsqldatabase.h>

namespace fbt
{
	class SqlConnection
	{
	public:
		static QSqlDatabase* getInstance();
		static void destroyInstance();

	private:
		static QSqlDatabase instance_;
	};
}
