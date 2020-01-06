//
// Created by nofar on 04/01/2020.
//

#include "Parser.h"

Parser::Parser(Map_Params *map_params_input, Map_Params *map_params_output, queue<string>*q){
this ->q = q;
this -> map_params_output = map_params_output;
this -> map_params_input = map_params_input;
}

void Parser::parser(string* commands){
    unordered_map<string,int> order_map={
            {"/sim/time/warp",2},
            {"/controls/switches/magnetos", 3},
            {"/controls/engines/current-engine/throttle",26},
            {"/controls/engines/current-engine/mixture",33},
            {"/controls/switches/master-bat",34},
            {"/controls/switches/master-alt",35},
            {"/controls/switches/master-avionics",27},
            {"/sim/model/c172p/brake-parking",31},
            {"/controls/engines/engine/primer",32},
            {"/controls/switches/starter",28},
            {"/controls/flight/speedbrake",30},
            {"/instrumentation/heading-indicator/offset-deg",4},
            {"/instrumentation/airspeed-indicator/indicated-speed-kt",1},
            {"/instrumentation/attitude-indicator/indicated-roll-deg",8},
            {"/instrumentation/attitude-indicator/internal-pitch-deg",9},
            {"/controls/flight/rudder",23},
            {"/controls/flight/aileron",21},
            {"/controls/flight/elevator",22},
            {"/instrumentation/altimeter/indicated-altitude-ft",5},
            {"/engines/engine/rpm",36},
            {"/instrumentation/altimeter/pressure-alt-ft",6},
            {"/instrumentation/attitude-indicator/indicated-pitch-deg",7},
            {"/instrumentation/attitude-indicator/internal-roll-deg",10},
            {"/instrumentation/encoder/indicated-altitude-ft",11},
            {"/instrumentation/encoder/pressure-alt-ft",12},
            {"/instrumentation/gps/indicated-altitude-ft",13},
            {"/instrumentation/gps/indicated-ground-speed-kt",14},
            {"/instrumentation/gps/indicated-vertical-speed",15},
            {"/instrumentation/heading-indicator/indicated-heading-deg",16},
            {"/instrumentation/magnetic-compass/indicated-heading-deg",17},
            {"/instrumentation/slip-skid-ball/indicated-slip-skid",18},
            {"/instrumentation/turn-indicator/indicated-turn-rate",19},
            {"/instrumentation/vertical-speed-indicator/indicated-speed-fpm",20},
            {"/controls/flight/flaps",24},
            {"/controls/engines/engine/throttle",25},
            {"/engines/active-engine/auto-start",29}
    };
    unordered_map<string,Command*> commands_map={
            {"openDataServer",new OpenServerCommand(map_params_input)},
            {"connectControlClient", new ConnectCommand(q)},
            {"var", new DefineVarCommand(map_params_output, map_params_input, &order_map)},
            {"=", new EqualCommand(q,map_params_output, map_params_input)},
            {"Sleep",new SleepCommand()},
            {"Print",new PrintCommand( map_params_input,map_params_output)},
            {"while",new WhileCommand(map_params_input,map_params_output,q)},
            {"if",new IfCommand(map_params_input,map_params_output,q)},
            {"}",new ConditionParser()}
    };
    int index = 0;
    Command* c = nullptr;
    while (!commands[index].empty()) {
        if(commands[index] == "done"){
            break;
        }
        if (commands[index + 1] == "=") {
            c = commands_map[commands[index + 1]];
        } else {
            c = commands_map[commands[index]];
        }
        if (c != NULL) {
            index += c->execute(commands + index);
        } else {
            break;
        }
    }
}