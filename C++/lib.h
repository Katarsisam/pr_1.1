
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>
using namespace std;
using JSON = nlohmann::json;

struct Node
{
    int n = 1;
    string str;
    Node* next;
};

class NodeX
{
private:
    Node* head;
public:
    
    NodeX();
    void insertAtFirstPos(string str);
    void insertAtEndPos(string str);
    void insertAtPos(string str, int pos);
    void deleteAtFirstPos();
    void deleteAtEndPos();
    void deleteAtPos(int pos);
    void printList();
    ~NodeX();
};

class JSONX
{
private:
    JSON json;
protected:
    void eraseAllSubStr(string & mainStr, const string & toErase);
    void eraseSubStrings(string & mainStr, const vector<string> & strList);
public:
    JSONX();
    string ReadingJSON (int indexObj);
    int IsJSONtb (string tb);
    void Remove(string& path);
    void ConfigurationParserJSON(string& path, int numbT);
    ~JSONX();
};


class CommandParser {
private:
    
public:

   void ComandStruct(const std::string& command);
    void ValInsert(const std::string& table);
    void  ColSelect(const string& tableName, const vector<string> columns);

};