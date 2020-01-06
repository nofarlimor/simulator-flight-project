//
// Created by nofar on 04/01/2020.
//

#include "IfCommand.h"
#include "EqualCommand.h"
#include "Parser.h"

IfCommand::IfCommand(Map_Params *map_params_in, Map_Params *map_params_out,queue<string>*q) {
    this -> map_params_out = map_params_out;
    this ->map_params_in = map_params_in;
    this->q=q;
}
IfCommand::IfCommand() = default;


int IfCommand::execute(string *s) {
    int i=0;
    while(s[i] != "}"){
        i++;
    }
//    vector<string> term;
//    for(int j=5;j<i;j++){
//        term.push_back(s[j]);
//    }
//    string *if_com = new string[term.size()];
//    for (int k = 0; k < term.size(); k++) {
//        if_com[k] = term.at(k);
//    }
    string L = clean_space(s[1]);
    string R = clean_space(s[3]);
    string op = s[2];

    double val_R = check_val(R);
    double val_L = check_val(L);

    if(this ->check_term(val_R,val_L,op)){
        cout<<"ok - if"<<endl;
        return 5;
//        Parser p(map_params_in,map_params_out,q);
//        p.parser(if_com);
    }
    return i+1;
}

bool IfCommand::check_term(double R, double L, string op) {
    if(op == "<") {
        if (L < R) {
            return true;
        }
    }
    if(op == ">"){
        if (L > R) {
            return true;
        }
    }
    if(op == "<="){
        if (L <= R) {
            return true;
        }
    }
    if(op == ">="){
        if (L >= R) {
            return true;
        }
    }
    if(op == "=="){
        if (L == R) {
            return true;
        }
    }
    if(op == "!="){
        if (L != R) {
            return true;
        }
    }
    return false;
}

double IfCommand::check_val(string str) {
    EqualCommand e;
    double v;
    string s_out = map_params_out->set_var();
    string s_in =map_params_in->set_var();
    Interpreter *inter = new Interpreter();
    Expression *ex = nullptr;
    inter->setVariables(s_in);
    inter->setVariables(s_out);
    ex = inter->interpret(str);
    v = ex->calculate();
    return v;
}

string IfCommand::clean_space(string xs) {
    string x=xs;
    string y = "";
    for (int i = 0; i < x.length(); i++) {
        if (x[i] != ' ') {
            y += x[i];
        }
    }
    return y;
}

