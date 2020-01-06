//
// Created by nofar on 05/01/2020.
//

#include "ConditionParser.h"

ConditionParser::ConditionParser() = default;

int ConditionParser::execute(string *s) {
    int i=0;
    while (s[i] != "while" && s[i] != "if"){
            i--;
    }
    if(s[i] == "while"){
        return i;
    }
    if(s[i] == "if"){
        return 1;
    }
}

