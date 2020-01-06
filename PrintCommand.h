//
// Created by nofar on 01/01/2020.
//

#ifndef EX3_PRINTCOMMAND_H
#define EX3_PRINTCOMMAND_H
#include "Command.h"
#include "Map_Params.h"
#include <iostream>
class PrintCommand:public Command {
private:
    Map_Params *map_params_out;
    Map_Params *map_params_in;
public:
    PrintCommand(  Map_Params *map_params_in,   Map_Params *map_params_out);
    virtual int execute(string *s);
};


#endif //EX3_PRINTCOMMAND_H
