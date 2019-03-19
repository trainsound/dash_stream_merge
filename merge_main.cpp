#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <error.h>
#include <vector>
#include <algorithm>

#define DIR_PATH "./"

typedef enum{
    M4I = 0,
    M4V = 1,
    M4A = 2
}FileExtension;

int getFileListCurrentDir(std::vector<std::string> &vfiles){
    DIR *dir;
    struct dirent *ent;
    dir = opendir (DIR_PATH);

    if(dir == NULL){
        std::cout<<"not found path: "<< DIR_PATH <<std::endl;
        return -1;
    }

    while ((ent = readdir (dir)) != NULL) {
        vfiles.push_back(ent->d_name);        
    }

    closedir (dir);
    
    return 0;
}

FileExtension parsingString(std::string fileName){
    // fileName.+

    // for(int n = fileName.length - 5; n < fileName.length; n++){
    //     if(fileName.c_str)
    // }
    return M4I;
}

int classifyFile(std::vector<std::string> &m4i, std::vector<std::string> &m4v, std::vector<std::string> &m4a, std::vector<std::string> &vfiles){
    for(int n = 0; n < vfiles.size(); n++){
        if(parsingString(vfiles[n]) == M4I){
            m4i.push_back(vfiles[n]);
        }else if(parsingString(vfiles[n]) == M4V){
            m4v.push_back(vfiles[n]);
        }else if(parsingString(vfiles[n]) == M4A){
            m4a.push_back(vfiles[n]);
        }
    }
    return 0;
}

int mergeVideo(std::vector<std::string> &m4i, std::vector<std::string> &m4v){

}

int mergeAudio(std::vector<std::string> &m4i, std::vector<std::string> &m4a){

}

int main(void){
    std::vector<std::string> vfiles;
    std::vector<std::string> m4i, m4v, m4a;

    //file reads to be in directories
    getFileListCurrentDir(vfiles);

    //sort the files
    sort(vfiles.begin(), vfiles.end());

    for(int n = 0; n < vfiles.size(); n++){
        std::cout<<vfiles[n]<<std::endl;
    }

    //clasify the files, m4i, m4v, m4a
    classifyFile(m4i, m4v, m4a, vfiles);

    //merge
    mergeVideo(m4i, m4v);
    mergeAudio(m4i, m4a);

    return 0;
}