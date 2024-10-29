#include <string>
#include <algorithm>
#include <vector>
#include "lib.h"
using namespace std;


void JSONX::eraseAllSubStr(string & mainStr, const string & toErase)
{
    size_t pos = string::npos;
    
    while ((pos = mainStr.find(toErase) )!= string::npos)  
        mainStr.erase(pos, toErase.length());
    
}

void JSONX::eraseSubStrings(std::string & mainStr, const std::vector<std::string> & strList)
{
    for (std::vector<std::string>::const_iterator it = strList.begin(); it != strList.end(); it++)
    {
        eraseAllSubStr(mainStr, *it);
    }
}


void CommandParser :: ComandStruct(const std::string& command) {
        istringstream iss(command);
        string keyword;
        iss >> keyword;

     if (keyword == "INSERT" || keyword == "insert") {
            string into;
            iss >> into;
            if (into == "INTO" || into == "into") {
                string tableName;
                iss >> tableName;
                if (tableName.empty()) {
                    cerr << "Error: Missing table name." << std::endl;
                    return;
                }
                string values;
                iss >> values;
                if (values != "VALUES" && values != "values") {
                    cerr << "Error: Missing 'VALUES' keyword." << std::endl;
                    return;
                }
                string key, value;
                iss >> key >> value;
                //db.insertInto(tableName, key, value);
            }
            else {
                std::cerr << "Error: Missing 'INTO' keyword." << std::endl;
            }
        }
        else if (keyword == "SELECT" || keyword == "select") {
            vector<string> columns;
            for(string cl : columns)
                if (cl != "FROM" || cl != "from")
                    iss >> cl;
                else
                    break;
            string from;
            iss >> from;
            if (from == "FROM" || from == "from") {
                string tableName;
                iss >> tableName;
                if (tableName.empty()) {
                    cerr << "Error: Missing table name." << std::endl;
                    return;
                }
                //db.selectFrom(tableName, column1, column2);
            }
            else {
                cerr << "Error: Missing 'FROM' keyword." << std::endl;
            }
        }
        else {
            cerr << "Error: Unknown command." << std::endl;
        }
    }