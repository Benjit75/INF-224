//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Media.h"
#include "Photo.h"
#include "Video.h"

using namespace std;

int main(int argc, const char* argv[])
{
    Media ** multimedias = new Media * [10];
    for (int count = 0; count < 10; count++){
        unsigned int r = rand()%2;
        if (r == 0){
            multimedias[count] = new Photo("photo" + to_string(count), "Folder/Photos/" + to_string(count), 10, 10);
        } else {
            multimedias[count] = new Video("video" + to_string(count), "Folder/Videos/" + to_string(count), 30);
        }
    }

    for (int count = 0; count < 10; count++){
        multimedias[count]->openMedia();
    }
    
    return 0;
}
