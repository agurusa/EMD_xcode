//
//  FTP_comm.hpp
//  EMD_xcode
//
//  Created by System Administrator on 1/17/17.
//  Copyright © 2017 Aarthi Gurusami. All rights reserved.
//

#ifndef FTP_comm_hpp
#define FTP_comm_hpp

#include <stdio.h>
#include <string>
#include <curl/curl.h>

class FTP_comm{
public:
    FTP_comm(); //constructor function
    //input the ip address of the file
    //input username and password
    void DownloadFile();
    //input file location
    //input file output location
    //write the data recieved to the output file location
    
    size_t WriteData(void *ptr, size_t size, size_t nmemb, FILE *stream);
private:
    CURL *curl;
    FILE *file;
    CURLcode res;
    const char *url;
    char outfilename[FILENAME_MAX] = "something.csv";
};

#endif /* FTP_comm_hpp */
