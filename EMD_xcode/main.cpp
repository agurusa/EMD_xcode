//
//  main.cpp
//  EMD_xcode
//
//  Created by Aarthi Gurusami on 1/13/17.
//  Copyright © 2017 Aarthi Gurusami. All rights reserved.
//

#include <iostream>
#include "EMD_comm.hpp"
#include "FTP_comm.hpp"

//instantiate a new communicator

EMD_comm communicator;
FTP_comm ftp;

int main(int argc, const char * argv[]) {
    //communicator.AttemptConnection();
    //if (communicator.IsConnectionMade()){
      //  communicator.BindConnection();
        //communicator.MakeRemoteConnection();
        //communicator.ReceiveByes();
        //communicator.SendFileRequest("ver\r\n");
        //communicator.ReceiveByes();

    //};
    ftp.DownloadFile();
    FILE *file;
    file = fopen("something.csv", "r");
    if (!file){
        printf("what");
    }
    int c;
    while(1){
        c = fgetc(file);
        if(feof(file)){
            break;
        }
        printf("%c", c);
    }
    fclose(file);
    
    return 0;
}
