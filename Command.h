//
// Created by nofar on 23/12/2019.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H

using namespace std;
#include <string>

class Command {

public:
    Command ()= default;;
    virtual int execute(string *s){};
};


#endif //EX3_COMMAND_H
