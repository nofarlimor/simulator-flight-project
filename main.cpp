using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <regex>
#include "Command.h"
#include "Parser.h"
//#include "OpenServerCommand.h"
//#include "ConnectCommand.h"
//#include "DefineVarCommand.h"
//#include "Server.cpp"
//#include "Client.cpp"
//#include "Map_Params.h"
//#include "EqualCommand.h"
//#include <queue>
//#include "PrintCommand.h"
//#include "SleepCommand.h"
//#include "WhileCommand.h"
//#include "IfCommand.h"


string *lexer(string file_name) {
    ifstream rf;
    rf.open("../" + file_name);
    if (!rf) {
        throw "File doesn't exist";
    }
    string buffer, temp;
    vector<string> data;
    smatch m;
    regex parans("[a-zA-Z0-9]+\\(.*");
    while (!rf.eof()) {
        rf >> buffer;
        if (regex_match(buffer, parans)) {
            while(buffer.find(')') == std::string::npos) {
                rf >> temp;
                buffer.append(" " + temp);
            }
            size_t found = buffer.find('(');
            data.push_back(buffer.substr(0, found));
            buffer = buffer.substr(found);
            buffer = buffer.substr(1, buffer.size() - 2);
            size_t found2 = buffer.find(',');
            while (found2 != std::string::npos) {
                if (buffer.substr(0, found2).front() == '\"')
                    data.push_back(buffer.substr(1, found2 - 2));
                else
                    data.push_back(buffer.substr(0, found2));
                buffer = buffer.substr(found2 + 1);
                found2 = buffer.find(',');
            }
            if (buffer.front() == '\"')
                data.push_back(buffer.substr(1, buffer.size() - 2));
            else
                data.push_back(buffer.substr(0, buffer.size()));
        } else if(buffer == "="){
            data.push_back(buffer);
            getline(rf, buffer);
            data.push_back(buffer);
        } else {
            data.push_back(buffer);
        }

    }
    rf.close();

    string *result = new string[data.size()];
    for (int i = 0; i < data.size(); i++) {
        result[i] = data.at(i);
    }
    return result;
}


int main(int argc, char**argv) {
    string *commands = lexer(argv[1]);
    class Map_Params map_params_output;
    class Map_Params map_params_input;
    queue<string> queue;
    Parser p (&map_params_input, &map_params_output,&queue);
    p.parser(commands);

    cout<<"output:";
    map_params_output.print_map();
    cout<<endl;
    cout<<"input:";
    map_params_input.print_map();
}

