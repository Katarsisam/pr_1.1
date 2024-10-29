#include "lib.h"
#include <string>
#include <fstream>  
#include <nlohmann/json.hpp>
#include <filesystem>

using namespace std;

using JSON = nlohmann::json;

int main(){
    string str, path;
    char var;
    Node *Test = new Node();
    SUBD *_system = new SUBD(Test);
    // Note that this is a relative path
    JSONX *jx = new JSONX();
    
    try{
        jx->ConfigurationParserJSON(path,0);
        jx->ConfigurationParserJSON(path,1);
        
    }catch(...){
        cout << "Error :  " << path << endl;
        cout << "Do you want rebuild schema? [Y/N]: ";
    do{
        cin >> var;
        switch (var)
        {
        case 'Y':
            jx->Remove(path);
            jx->ConfigurationParserJSON(path,0);
            jx->ConfigurationParserJSON(path,1);
            break;
        case 'N':
            break;
        default:
            cout << "Do you want rebuild schemf? [Y/N]: ";
            break;
        }
    }while(var != 'Y' && var != 'N');
    }
    
    
    
    
    
   // getline(cin,str,';');
    
    
    return 0;
}


