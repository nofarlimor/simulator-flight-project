//
// Created by nofar on 04/01/2020.
//

#ifndef EX3_PARSER_H
#define EX3_PARSER_H
using namespace std;
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <regex>
#include "Command.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "Server.cpp"
#include "Client.cpp"
#include "Map_Params.h"
#include "EqualCommand.h"
#include <queue>
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "ConditionParser.h"

class Parser {
private:
    Map_Params *map_params_input;
    Map_Params *map_params_output;
    queue<string>*q;
public:
    Parser(Map_Params *map_params_input, Map_Params *map_params_output, queue<string>*q);
    void parser (string* commands);
};


#endif //EX3_PARSER_H
