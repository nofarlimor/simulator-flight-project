//
// Created by nofar on 23/12/2019.
//

#ifndef EX3_CONNECTCOMMAND_H
#define EX3_CONNECTCOMMAND_H


#include "Command.h"
#include "Map_Params.h"
#include <queue>

class ConnectCommand : public Command {
private:
  //  Map_Params* map_params;
  queue<string>*q;

public:
    ConnectCommand(queue<string>*q);
    virtual int execute(string *s);
    void write_to_server(int client);
};

#endif //EX3_CONNECTCOMMAND_H
