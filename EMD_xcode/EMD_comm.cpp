//
//  EMD_comm.cpp
//  EMD_xcode
//
//  Created by Aarthi Gurusami on 1/13/17.
//  Copyright © 2017 Aarthi Gurusami. All rights reserved.
//

#include "EMD_comm.hpp"

EMD_comm::EMD_comm(){
    IPAddress = "xx.xx.xxx.xxx";
    sock = 1; //just chose a random integer here
    PortNumber = 23; //telnet port
    BufferSize = 512;
}

int EMD_comm::AttemptConnection(){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    return sock;
}

bool EMD_comm::IsConnectionMade(){
    if (sock < 0){
        perror("socket\n");
        return false;
    }
    else {
        printf("socket made\n");
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
        perror("bind failed\n");
    }
    else{
        printf("bind successful\n");
    }
    
}

void EMD_comm::MakeRemoteConnection(){
    int connectionResult;
    struct sockaddr_in remoteaddr;
    remoteaddr.sin_family = AF_INET; //TODO: make this globally available
    inet_pton(AF_INET, IPAddress, &(remoteaddr.sin_addr));
    remoteaddr.sin_port = htons(PortNumber);
    connectionResult = connect(sock, (struct sockaddr *)&remoteaddr, sizeof(remoteaddr));
    if (connectionResult< 0){
        perror("remote connection failed \n");
    }
    else{
        printf("remote connection successful.\n");
    }
}

void EMD_comm::SendFileRequest(std::string message){
    ssize_t sentBytes;
    sentBytes = send(sock, &message, message.size(), 0); // not sure what this flag does...(terminates a recored, if supported by the protocol)
    if (sentBytes < 0){
        perror("send error. \n");
    }
    else
        printf("%zu\n", sentBytes);
    
}

void EMD_comm::ReceiveByes(){
    char buffer[BufferSize];
        recv(sock, &buffer, BufferSize, 0);
        printf("%s", buffer);
}
