#pragma once

#include "database.h"
#include "column.h"

typedef std::vector<Entry> Group;

class DatabaseExt: public Database
{
public:
    DatabaseExt(): Database() {}
    virtual ~DatabaseExt() = default;

    QueryResult selectAllFrom(const std::string &tableName, const std::vector<Column> &columns,
                              const Expr &expr, const std::string* fileName,
                              const std::vector<std::string>& groupByColumns,
                              const std::vector<Column> &orderByColumns);
    QueryResult selectFrom(const std::string &tableName,
                           const std::vector<std::string> &keyNames, const Expr &expr, const std::string* file_name,
                           const std::vector<std::string> &groupByColumn, std::string *orderByKey);

    void getCountNames(const std::vector<std::string> &keyNames,
                      std::vector<std::string> &_keyNames,
                      std::vector<std::string> &_cntNames,
                      std::vector<size_t> &cntPos);
    void countEntries(const std::vector<std::string> &keyNames,
                      const std::vector<std::string> &cntNames,
                      const std::vector<size_t> &cntPos,
                      const std::vector<Entry> &entries,
                      std::vector<Entry> &resultEntries);

    void gatherEntries(const std::vector<Column> &columns,
                       const std::vector<std::string> &keyNames,
                       const std::vector<Entry> &entries,
                       Entry &resultEntries);
    void orderEntriesBy(std::vector<Entry> &entries, const std::vector<Column> &columns, const std::vector<Column> &orderByColumns);

    void makeGroupBy(const std::vector<std::string> &groupByKey,
                     const std::vector<std::string> &keyNames,
                     const Group &entries, std::vector<Group> &groups);

    void load(const std::string &tableName, const std::vector< std::map<std::string, Variant> > &entries);
};