#include<iostream>
#include<unistd.h>
#include <sys/wait.h>
#include "string"
int main(){


    std::string fileName = "test.txt";
    std::string text = "Es im anush Hayastani arevaham barn em sirum." "\n"
                        "asdsaddasd"  "\n"
                        "anush lini."  "\n"
                        "asdasdad"  "\n"
                        "Inga Anush Arshakyanner."  "\n"
                        "aaaannnnnuuussshhh";
    std::string pattern = "anush";
    auto str = "echo '" + text + "' > " + fileName;
    auto prepare_p_id = fork();
    if(prepare_p_id == 0){
        auto ret = execl("/bin/bash", "bash", "-c", str.c_str(), NULL);
        return ret;
    }
    
    wait(NULL);
    
    auto c_pid = fork();

    if(c_pid > 0){
        // parent context
        // parent process forkes new child process
        wait(NULL);
        std::cout << "Parent process done" << std::endl;
    }
    else if(c_pid == 0){
        // childs context
        auto ret = execl ("/bin/grep", "grep", "-i", "anush", fileName.c_str(), NULL);
        if (ret == -1)
            perror ("execl");
    }
    
    return 0;
}
