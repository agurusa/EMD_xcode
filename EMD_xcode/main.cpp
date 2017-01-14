//
//  main.cpp
//  EMD_xcode
//
//  Created by Aarthi Gurusami on 1/13/17.
//  Copyright © 2017 Aarthi Gurusami. All rights reserved.
//

#include <iostream>
#include "EMD_comm.hpp"

//instantiate a new communicator

EMD_comm communicator;

int main(int argc, const char * argv[]) {
    communicator.AttemptConnection();
    if (communicator.IsConnectionMade()){
        communicator.BindConnection();
        communicator.MakeRemoteConnection();
        communicator.ReceiveByes();
        communicator.SendFileRequest("ver\r\n");
        communicator.ReceiveByes();

    };
    
    return 0;
}
