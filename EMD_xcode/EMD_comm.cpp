//
//  EMD_comm.cpp
//  EMD_xcode
//
//  Created by Aarthi Gurusami on 1/13/17.
//  Copyright © 2017 Aarthi Gurusami. All rights reserved.
//

#include "EMD_comm.hpp"

EMD_comm::EMD_comm(){
    sock = 1; //just chose a random integer here
    PortNumber = 23; //telnet port
}

int EMD_comm::AttemptConnection(){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    return sock;
}

bool EMD_comm::IsConnectionMade(){
    if (sock < 0){
        perror("socket");
        return false;
    }
    else {
        printf("socket made");
        return sock != -1; //if the socket does not return -1, the connection has been made successfully.
    }
}

void EMD_comm::BindConnection(){
    int bindResult;
    struct sockaddr_in myaddr;
    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);//this is the current machine's IP address. Here, wer'e not specifying a specific interface and are allowing the OS to use whatever it wants. (0.0.0.0)
    myaddr.sin_port = htons(PortNumber);
    bindResult = bind(sock, (sockaddr *)&myaddr, sizeof(myaddr)); //not sure what the (sockaddr*)& symbol does
    //TODO: maybe combine this in IsConnectionMade()
    if (bindResult < 0){
        perror("bind failed");
    }
    else{
        printf("bind successful");
    }
    
}
