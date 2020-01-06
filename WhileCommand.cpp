//
// Created by nofar on 01/01/2020.
//

#include "WhileCommand.h"
#include "EqualCommand.h"
#include "IfCommand.h"

WhileCommand::WhileCommand(Map_Params *map_params_in, Map_Params *map_params_out,queue<string>*q) {
    this -> map_params_out = map_params_out;
    this ->map_params_in = map_params_in;
    this->q=q;
}

int WhileCommand::execute(string *s) {
    int i=0;
    while(s[i] != "}"){
        i++;
    }
//    vector<string> t;
//    for(int j=5;j<i;j++){
//        t.push_back(s[j]);
//    }
//    string *if_c = new string[t.size()];
//    for (int k = 0; k < t.size(); k++) {
//        if_c[k] = t.at(k);
//    }
    IfCommand x(map_params_in,map_params_out,q);
    string L = x.clean_space(s[1]);
    string R = x.clean_space(s[3]);
    string op = s[2];

    double val_R = x.check_val(R);
    double val_L = x.check_val(L);

    if (x.check_term(val_R,val_L,op)){
        cout<<"true while"<<endl;
        return 5;
//        Parser p(map_params_in,map_params_out,q);
//        p.parser(if_c);
    }
    return i+1;
}





