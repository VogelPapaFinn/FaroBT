#pragma once

#include "dep/log/easylogging++.h"

#include <vector>

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
