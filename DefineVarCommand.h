//
// Created by nofar on 23/12/2019.
//

#ifndef EX3_DEFINEVARCOMMAND_H
#define EX3_DEFINEVARCOMMAND_H


#include "Command.h"
#include "Map_Params.h"
#include <unordered_map>
#include<regex>

class DefineVarCommand:public Command{
private:
    Map_Params* map_params_input;
    Map_Params* map_params_output;
    unordered_map<string,int>* map_order;

public:
    DefineVarCommand(Map_Params *out_Params,Map_Params *in_Params,unordered_map<string,int> *order );
    virtual int execute(string *s);
};

#endif //EX3_DEFINEVARCOMMAND_H
