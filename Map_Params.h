//
// Created by nofar on 28/12/2019.
//

#ifndef EX3_MAP_PARAMS_H
#define EX3_MAP_PARAMS_H
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


class Map_Params {

private:

    struct params{
        string node;
        double val;
        int index;
    };
    unordered_map<string, params> symbol_table;


public:

    void add_Params(string name, string node, double val, int index); // add new params to map

    double get_Params(string name); // get value of param according to name

    string get_Params_path(string name);

    void set_params(string var_name, double value); // set the value of the params

    void print_map ();

    void update (vector<string> v );

    bool search(string name);

    string set_var ();
};

#endif //EX3_MAP_PARAMS_H
