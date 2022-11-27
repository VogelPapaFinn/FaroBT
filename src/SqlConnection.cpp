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
		if(instance_.open()) LOG(INFO) << "Established connection to sql database.";
		else LOG(ERROR) << "Could'nt establish connection to sql database.";
		return &instance_;
	}

	void SqlConnection::destroyInstance()
	{
		if (instance_.isOpen()) instance_.close();
	}
}