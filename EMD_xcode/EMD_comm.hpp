//
//  EMD_comm.hpp
//  EMD_xcode
//
//  Created by Aarthi Gurusami on 1/13/17.
//  Copyright © 2017 Aarthi Gurusami. All rights reserved.
//

#ifndef EMD_comm_hpp
#define EMD_comm_hpp

#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h> //needed for sockaddr struct
#include <arpa/inet.h> //needed for inet_pton 



class EMD_comm{
public:
    EMD_comm(); //constructor function
    // open a telnet connection
    // tell it what IP address its looking for
    // if it found it
				// good
    //if it didn't
				// tell that it didn't / why
    
    // open an FTP connection
    // tell it what IP address its looking for
    // if it found it
				// good
    //if it didn't
				// tell that it didn't / why
    
    bool IsConnectionMade(); //TODO: make this an enum
    int AttemptConnection();
    void BindConnection();
    void MakeRemoteConnection();
    // send out a request for a file
    void SendFileRequest(std::string message);
    // receive the data from the file and save it locally
    // graph it
    
    void Reset();
private:
    //initialize in constructor function
    const char *IPAddress;
    int PortNumber;
    int BufferSize;
    int sock; //ends up being the socket that is created
    
};

#endif /* EMD_comm_hpp */
