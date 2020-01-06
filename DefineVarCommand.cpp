using namespace std;

#include <iostream>
#include "DefineVarCommand.h"
#include "EqualCommand.h"
#include "Expression/Interpreter.h"


DefineVarCommand::DefineVarCommand(Map_Params *out_Params, Map_Params *in_Params, unordered_map<string, int> *order) {
    this->map_params_input = in_Params;
    this->map_params_output = out_Params;
    this->map_order = order;
}

int DefineVarCommand::execute(string *s) {

    string param_name = s[1];
    string direct = s[2];
    string path = s[4];
    string param = s[3];

    string x = param;
    string y = "";
    for (int i = 0; i < x.length(); i++) {
        if (x[i] != ' ') {
            y += x[i];
        }
    }

    if (direct == "->") {
        this->map_params_output->add_Params(param_name, path, 0.0, 0);
    } else {
        if (direct == "<-") {
            this->map_params_input->add_Params(param_name, path, 0.0, map_order->find(path)->second);
        } else {
            EqualCommand e;
            double v;
            string s_out = map_params_output->set_var();
            string s_in = map_params_input->set_var();
            Interpreter *inter = new Interpreter();
            Expression *ex = nullptr;
            inter->setVariables(s_in);
            inter->setVariables(s_out);
            ex = inter->interpret(y);
            v = ex->calculate();
            this->map_params_output->add_Params(param_name, "", v, 0);
            return 4;
        }
    }
    int index = 5;
    return index;
}


