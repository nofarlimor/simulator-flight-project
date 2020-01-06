//
// Created by nofar on 05/01/2020.
//

#ifndef EX3_CONDITIONPARSER_H
#define EX3_CONDITIONPARSER_H
#include "Command.h"
#include "Map_Params.h"
#include <iostream>
#include <queue>

class ConditionParser: public Command{
public:
    virtual int execute(string *s);
    ConditionParser();
};


#endif //EX3_CONDITIONPARSER_H
