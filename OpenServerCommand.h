//
// Created by nofar on 23/12/2019.
//

#ifndef EX3_OPENSERVERCOMMAND_H
#define EX3_OPENSERVERCOMMAND_H

#include "Command.h"
#include "Map_Params.h"


class OpenServerCommand : public Command {
private:
    Map_Params* map_params;

public:
    OpenServerCommand(Map_Params *pParams);
    virtual int execute(string *s);
    void serverThread (int client_socket);
};



#endif //EX3_OPENSERVERCOMMAND_H
