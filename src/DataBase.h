#pragma once

#include <string>
#include <map>

#include "DataTable.h"

class DataBase {

private:
	std::map<std::string, DataTable*> mTable;
	DataTable* mWorkTable;

public:
	void createTable(const std::string &command);
	void dropTable(const std::string &tableName);
	void showTable(const std::string &tableName);
	void showTableAll();

	void insertData(const std::vector<std::string> &param);
	void deleteData(const std::vector<std::string> &param);
	void updateData(const std::vector<std::string> &param);
	void selectData(const std::vector<std::string> &param);
};