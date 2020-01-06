//
// Created by nofar on 23/12/2019.
//

#include "ConnectCommand.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <mutex>
#include <thread>


ConnectCommand::ConnectCommand(queue<string>*q) {
    this->q = q;
}


int ConnectCommand::execute(string *s) {
    string x = s[1];
    string y="";
    for (int i =0 ; i<x.length(); i++){
       if(x[i] != '"' ) {
           y += x[i];
       }
   }
    const char *IP = y.c_str();
    int PORT = stoi(s[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }

    //We need to create a sockaddr obj to hold address of server
    sockaddr_in address{}; //in means IP4
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr(IP);  //the localhost address
    address.sin_port = htons(PORT);
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server on local host with port 8081
    int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        std::cerr << "Could not connect to host server" << std::endl;
        return -2;
    } else {
        std::cout << "Client is now connected to server" << std::endl;
    }

    //if here we made a connection
//    string com_s = this->q->front();
//    int is_sent = send(client_socket, com_s.c_str(), com_s.length(), 0);
//    if (is_sent == -1) {
//        std::cout << "Error sending message" << std::endl;
//    } else {
//        std::cout << "Hello message sent to server" << std::endl;
//    }
//    this->q->pop();

//    char buffer[1024] = {0};
//    int valread = read(client_socket, buffer, 1024);
//    std::cout << buffer << std::endl;

    thread thred_client([client_socket,this]{write_to_server(client_socket);});
    thred_client.detach();

//    close(client_socket);

    int index = 3;
    return index;
}

void ConnectCommand::write_to_server(int client) {
    mutex lock2;
    while(true){
        while(!q->empty()) {
            lock2.try_lock();
            string com_s = this->q->front();
            std::cout << com_s << std::endl;
            int is_sent = send(client, com_s.c_str(), com_s.length(), 0);
            if (is_sent == -1) {
                throw "Error sending message";
            } else {
//                std::cout << com_s << std::endl;
            }
            this->q->pop();
            lock2.unlock();
        }
    }
}


