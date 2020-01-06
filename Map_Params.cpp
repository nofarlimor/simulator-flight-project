//
// Created by nofar on 28/12/2019.
//

#include <iostream>
#include <iomanip>

#include "Map_Params.h"


void Map_Params::add_Params (string name, string path, double val, int index) {
    params p;
    p.node = path;
    p.val = val;
    p.index = index;

    this -> symbol_table[name] = p;
}

double Map_Params::get_Params(string param) {
    return this -> symbol_table.find(param)->second.val;
}

string Map_Params::get_Params_path(string param) {
    return this -> symbol_table.find(param)->second.node;
}

void Map_Params::set_params(string var_name, double value) {
    this->symbol_table.find(var_name)->second.val = value;
}

void Map_Params::print_map (){
    for(auto x : this->symbol_table){
        cout << x.first << " "<<get_Params(x.first)<<" "<<x.second.index<<endl;
    }
}

void Map_Params::update(vector<string> v) {
  for(auto x:this -> symbol_table){
     this->set_params(x.first,stod(v[(x.second.index)-1]));
  }
//  cout<<"update:"<<endl;
//  this ->print_map();
}

bool Map_Params::search(string name) {
   if(this->symbol_table.find(name) == this->symbol_table.end()){
       return false;
   } else{
       return true;
   }
}

string Map_Params::set_var() {
    string s ="";
    for(auto x : this->symbol_table){
       s+= (x.first+"="+to_string(get_Params(x.first))+";");
    }
    return s;
}


