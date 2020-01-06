//
// Created by nofar on 31/12/2019.
//

#ifndef EX3_EQUALCOMMAND_H
#define EX3_EQUALCOMMAND_H
#include "Command.h"
#include "Map_Params.h"
#include <queue>
#include <iostream>
#include <regex>
#include "Expression/Interpreter.h"
#include "Expression/Expression.h"
class EqualCommand:public Command {
private:
    queue<string>* que{};
    Map_Params *map_params_in{};
    Map_Params *map_params_out{};
public:
    EqualCommand(queue<string> *q, Map_Params *map_params_out, Map_Params *map_params_in);
    EqualCommand();
    virtual int execute(string *s);

};


#endif //EX3_EQUALCOMMAND_H


