//
// Created by nofar on 01/01/2020.
//

#ifndef EX3_SLEEPCOMMAND_H
#define EX3_SLEEPCOMMAND_H
#include "Command.h"
#include <thread>
#include <mutex>

class SleepCommand:public Command{
private:
    mutex lock_sleep;
public:
    virtual int execute(string *s);
    void sleep_fun(string time);
};


#endif //EX3_SLEEPCOMMAND_H
