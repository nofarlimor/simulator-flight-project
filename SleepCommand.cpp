//
// Created by nofar on 01/01/2020.
//

#include "SleepCommand.h"
#include<iostream>
int SleepCommand::execute(string *s) {
string total_time = s[1];
 thread threadsleep([total_time,this]{sleep_fun(total_time);});
 threadsleep.join();
    cout<<"sleep"<<endl;
    return 2;
}

void SleepCommand::sleep_fun(string time) {
    lock_sleep.lock();
    long t = stol(time);
    std::this_thread::sleep_for(std::chrono::milliseconds(t));
    lock_sleep.unlock();
}
