#include<iostream>
#include<unistd.h>

int main(){

    std::cout << "HEAD " << getpid() << std::endl;

    int forksCount = 3;
    int level = 0;
    for(int i = 0; i < forksCount; ++i){
        auto pids_i = fork();
        if(pids_i > 0){
            std::cout << "\t" << getpid() << " spawns child " << pids_i << std::endl;
        }
        else if(pids_i == 0){
            level++;
            std::cout << "HEAD^" << level << ", " << getpid() << " working"  << std::endl;
        }
    }
    
    return 0;
}
