#pragma once

#include "easylogging++.h"

#include <vector>

#include <qsqldatabase.h>

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
