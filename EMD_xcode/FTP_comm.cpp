//
//  FTP_comm.cpp
//  EMD_xcode
//
//  Created by System Administrator on 1/17/17.
//  Copyright © 2017 Aarthi Gurusami. All rights reserved.
//

#include "FTP_comm.hpp"

FTP_comm::FTP_comm(){
    curl =curl_easy_init(); //returns a CURL easy handle that you use as input to other functions in the asy interface. MUST have a corresponding call to curl_easy_cleanup
    url = "xxx";
}

void FTP_comm::DownloadFile(){
    
    file = fopen(outfilename, "w");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &FTP_comm::WriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    fclose(file);
}

size_t FTP_comm::WriteData(void *ptr, size_t size, size_t nmemb, FILE *stream){
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}
