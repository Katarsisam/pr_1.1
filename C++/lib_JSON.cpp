#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include <filesystem>
#include <fstream> 
#include "lib.h"

using namespace std;

string JSONX :: ReadingJSON (int indexObj, JSON& j)
{
    string nameObj;
    JSON structureField = j;
    auto it = structureField.items().begin();
    advance(it,indexObj);
    nameObj = it.key();

    return nameObj;
}


void JSONX :: ConfigurationParserJSON(string& path, int numbT){
    vector<string> v {"[", "]", "\""};
    fstream fout;
    filesystem::path filepath;
    if(numbT < json["structure"].size()){
        
        path = json["name"].dump(-1,' ', false) + "/" + ReadingJSON(numbT,json["structure"]); //создание пути для журнала
        eraseSubStrings(path, v);
        filepath = path;
    }else{
        path = "Configuration doesnt exist";
        throw path;
        return;
    }


    string str;
    if(!filesystem::is_directory(filepath)){  //создание кофигурации
        filesystem::create_directories(filepath);
        fout.open(path + "/" + "1.csv", ios::out);
        ofstream file(path + "/" + "1.csv");
        str = to_string(json["structure"][ReadingJSON(numbT,json["structure"])]);
        eraseSubStrings(str, v);
        file << ReadingJSON(numbT,json["structure"]) + "_pk"<< "," << str << "\n";
        file.close();
    }else{
        path = "Directory already exist";
        throw path;
    }

}

//Удаление журнала
void JSONX :: Remove(string& path){
    
    vector<string> v {"[", "]", "\""};
    filesystem::path filepath;
    path = json["name"].dump(-1,' ', false);
    eraseSubStrings(path,v);
    filepath = path;
    filesystem::remove_all(filepath);
}


//Инициализация конфигурации
JSONX::JSONX() 
{
    ifstream fin("/mnt/d/J_CPRA_X64F/комаров/C++_2/pr_1/C++/schema.json");
    if(fin.is_open())
        json = JSON::parse(fin);
    fin.close();
}
JSONX::~JSONX()
{
}