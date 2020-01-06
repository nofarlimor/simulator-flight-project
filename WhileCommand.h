//
// Created by nofar on 01/01/2020.
//

#ifndef EX3_WHILECOMMAND_H
#define EX3_WHILECOMMAND_H
#include "ConditionParser.h"
#include "Map_Params.h"
#include <iostream>
#include <queue>
#include "Parser.h"

class WhileCommand:public ConditionParser{
private:
    Map_Params *map_params_out;
    Map_Params *map_params_in;
    queue<string>*q;
public:
    WhileCommand(Map_Params *map_params_in, Map_Params *map_params_out,queue<string>*q);
    virtual int execute(string *s);
};

#endif //EX3_WHILECOMMAND_H
