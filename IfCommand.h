//
// Created by nofar on 04/01/2020.
//

#ifndef EX3_IFCOMMAND_H
#define EX3_IFCOMMAND_H
#include "ConditionParser.h"
#include "Map_Params.h"
#include <iostream>
#include <queue>

class IfCommand:public ConditionParser {
private:
    Map_Params *map_params_out;
    Map_Params *map_params_in;
    queue<string>*q;
public:
    IfCommand(Map_Params *map_params_in, Map_Params *map_params_out,queue<string>*q);
    IfCommand();
    bool check_term(double R, double L, string op);
    double check_val (string str);
    virtual int execute(string *s);
    string clean_space(string x);

};


#endif //EX3_IFCOMMAND_H
