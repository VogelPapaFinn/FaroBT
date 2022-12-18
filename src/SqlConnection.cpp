#include "../include/SqlConnection.h"

namespace fbt
{
	// Initialize static instance_
	QSqlDatabase SqlConnection::instance_;

    std::shared_ptr<QSqlDatabase> SqlConnection::getInstance()
	{
		// Connection already exists
		if (instance_.isOpen()) return std::make_shared<QSqlDatabase>(instance_);

        // Load DB Driver
        instance_ = QSqlDatabase::addDatabase("QPSQL");
        if(!instance_.isValid()) SPDLOG_LOG_WARN("main", "QSqlDatabase Driver is invalid");

		// Connection doesn't exist. Establish new one
		instance_.setHostName("127.0.0.1");
		instance_.setDatabaseName("bugtracker");
		instance_.setUserName("postgres");
		instance_.setPassword("postgres");
		
		if (instance_.open()) SPDLOG_LOG_INFO("main", "Established database connection");
		else SPDLOG_LOG_WARN("main", "Failed to establish database connection");
		return std::make_shared<QSqlDatabase>(instance_);
	}
}