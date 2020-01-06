//
// Created by nofar on 01/01/2020.
//

#include "PrintCommand.h"

PrintCommand::PrintCommand(Map_Params *map_params_in, Map_Params *map_params_out) {
    this ->map_params_in = map_params_in;
    this ->map_params_out = map_params_out;
}

int PrintCommand::execute(string *s) {
    string str = s[1];
    double value;
    if(this->map_params_out->search(str)){
        value = this->map_params_out->get_Params(str);
        cout<<value<<endl;
    }else{
        if(this->map_params_in->search(str)){
            value = this->map_params_in->get_Params(str);
            cout<<value<<endl;
        }else{
            if(str == "done"){
                cout<<str<<endl;
               return 1;
            }else{
                cout<<str<<endl;
            }
        }
    }

    int index = 2;
    return index;
}

