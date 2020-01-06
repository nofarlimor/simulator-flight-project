#Homework3 -  flight simulator interpreter

#introduction with the project:
this project create interpreter that allows remote control of flight simulator.
in this project we learn how to work with server client communication.

#introduction with the simulator:
the simulator FlightGear is an open-source project. Among other things,
 this simulator is also a server that can be connected as a client or as a server. 
 This quality allows us to easily retrieve information about various flight parameters in real time
 and even inject commands to control the plane as we want.

#generic_small.xml file:
in this file we can find The values ​​we are going to sample from the simulator.
Before we start to run the project first, the file must be planted at the location where we installed the
FlightGear simulator.

#fly.txt file:
This file contains code designed to make the plane fly. 

#main:
the main contains a call for 2 functions: 
#lexer function: this function reads a file, and returns an array of commands strings and theres values and Implementation.
#parser function: this function run all over the string and in each time go to the execute of the object that we want to execute in the same read,
and execute him. 

#command:
in this class we use a command pattern and a map to associate a string command to the right object execute.
We will reach these objects with the help of the keys on the map which will be the names of the commands.

here we made the connection between the client and the server:
#openservercommand: This function opens a thread in the background that runs a server that listens to Port 5400 and reads each line. In each line we get a string of values ​​of the plane. We store these values ​​in the input_params map.
#connectcommand: Using this function, we connect as a client to the simulator in a separate thread, and here we send values ​​to the simulator to execute.

here we defind and connect the vars to the map:
#map_params: In this function we create 2 global maps with one containing the values ​​we send to the simulator while the other contains the values ​​we get from the simulator. The income is followed by the arrows.
#definevarcommand: In this function we create the variables we will work with during the project. Each variable contains the following information: the name of the variable, whether its value is inserted from the client or server, and its path in the simulator.
#equalcommand: In this function we update the value as written on our map and on the simulator.

condition commands:
#ifcommand: This function checks the if conditions, if the condition is good, the rows within the condition are executed until the bracket arrives.
#whilecommand :This function checks the while conditions, if the condition is good, the rows within the condition are executed until the bracket arrives. from that point it return to the while command and check again with the apdate term if the condition is good until the terms are no longer suitable.
#conditionparser:We arrive to this function when we reach bracket after executing a condition command. When it comes to the if command, we move on to the next line in the file, while when it comes to the while command, we go back to the while command and check if the condition again exists.

#printcommand: this function print the value or line is asking.
#sleepcommand: Pause the main thread.

github_link - 
