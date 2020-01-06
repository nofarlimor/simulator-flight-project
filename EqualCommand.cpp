//
// Created by nofar on 31/12/2019.
//

#include "EqualCommand.h"


EqualCommand::EqualCommand(queue<string> *q, Map_Params *map_params_out, Map_Params *map_params_in) {
 this ->que = q;
 this ->map_params_out = map_params_out;
 this ->map_params_in = map_params_in;
}

EqualCommand::EqualCommand() = default;


int EqualCommand::execute(string *s) {
    string x = s[2];
    string y = "";
    for (int i = 0; i < x.length(); i++) {
        if (x[i] != ' ') {
            y += x[i];
        }
    }
    double v;
    string s_out = map_params_out->set_var();
    string s_in =map_params_in->set_var();
    Interpreter *inter = new Interpreter();
    Expression *ex = nullptr;
    inter->setVariables(s_in);
    inter->setVariables(s_out);
    ex = inter->interpret(y);
    v = ex->calculate();

    string param_name = s[0];
    map_params_out->set_params(param_name,v);

   string path = map_params_out->get_Params_path(param_name);
   string val = to_string(v);

   string s_command = "set "+path+" "+val+"\r\n";
   que->push(s_command);

    return 3;
}



