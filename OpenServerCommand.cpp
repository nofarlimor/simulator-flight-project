using namespace std;

#include "OpenServerCommand.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <thread>
#include<regex>
#include <vector>
#include <mutex>

OpenServerCommand::OpenServerCommand(Map_Params *in_Params) {
    this->map_params = in_Params;
}


int OpenServerCommand::execute(string *s) {
    int PORT = stoi(*(s + 1));
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(PORT);
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }

    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);

    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
        return -4;
    }

    close(socketfd); //closing the listening socket


//    //writing back to client
//    char *hello = "Hello, I can hear you! \n";
//    send(client_socket, hello, strlen(hello), 0);
//    std::cout << "Hello message sent\n" << std::endl;

//thread threadOSC([client_socket,this]{serverThread(client_socket);});
//threadOSC.join();
//threadOSC.detach();

//
//    char buffer[1024] = {0};
//    int valread = read(client_socket, buffer, 1024);
//    cout << buffer << std::endl;
//
//    string buffer_s = buffer;
//    smatch m;
//    regex value(",");
//    regex value2("\\n");
//
//    vector<string> current_buffer;
//    while (current_buffer.size()<36){
//        if(regex_search(buffer_s, m, value)){
//            current_buffer.push_back(m.prefix());
//            buffer_s =m.suffix();
//        }else{
//            regex_search(buffer_s, m, value2);
//            current_buffer.push_back(m.prefix());
//        }
//    }
//    map_params->update(current_buffer);
//
//    for(int i=0; i<current_buffer.size();i++){
//        cout<<current_buffer[i]<<endl;
//    }

    thread threadOSC([client_socket, this] { serverThread(client_socket); });
    threadOSC.detach();

    int index = 2;
    return index;
}

void OpenServerCommand::serverThread(int client_socket) {
    char buffer[1024] = {0};
    string buffer_s, temp;
    smatch m;
    regex value(",");
    regex value2("\\n");
    vector<string> current_buffer;
    size_t found;
    int length;
    while (true) {
        while ((length = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
            buffer_s.append(buffer, length);
            if ((found = buffer_s.find("\n")) != std::string::npos) {
                temp = buffer_s.substr(0, found);
                buffer_s = buffer_s.substr(found + 1);
                while (!temp.empty()) {
                    if ((found = temp.find(",")) != std::string::npos) {
                        current_buffer.push_back(temp.substr(0, found));
                        temp = temp.substr(found + 1);
                    } else {
                        current_buffer.push_back(temp);
                        temp = "";
                    }
                }
                for (int i = 0; i < current_buffer.size(); i++)
//                    cout << current_buffer[i]<<",";
//                cout<<endl;
                map_params->update(current_buffer);
                current_buffer.clear();
                if (length == -1)
                    throw "not okay";
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }

        }


//       while (regex_match(buffer_s, value) || regex_match(buffer_s, value2)) {
//           if (regex_search(buffer_s, m, value)) {
//               current_buffer.push_back(m.prefix().str());
//               buffer_s = m.suffix().str();
//           } else if (regex_search(buffer_s, m, value2)) {
//               current_buffer.push_back(m.prefix().str());
//               buffer_s = m.suffix().str();
//           }
//       }
//       if (current_buffer.size() == 36)
//            map_params->update(current_buffer);
//       for (int i = 0; i < current_buffer.size(); i++) {
//           cout << current_buffer[i] << endl;
//       }

    }
}



