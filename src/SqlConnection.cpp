#include "../include/SqlConnection.h"

namespace fbt
{
	// Initialize static instance_
	QSqlDatabase SqlConnection::instance_ = QSqlDatabase::addDatabase("QPSQL");

	QSqlDatabase* SqlConnection::getInstance()
	{
		// Connection already exists
		if (instance_.isOpen()) return &instance_;

		// Connection doesnt exist. Establish new one
		instance_.setHostName("127.0.0.1");
		instance_.setDatabaseName("bugtracker");
		instance_.setUserName("postgres");
		instance_.setPassword("postgres");
		
		if (instance_.open()) SPDLOG_LOG_INFO("main", "Established database connection");
		else SPDLOG_LOG_WARN("main", "Failed to establish database connection");
		return &instance_;
	}

	void SqlConnection::destroyInstance()
	{
		if (instance_.isOpen()) instance_.close();
	}
}