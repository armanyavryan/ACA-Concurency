#include<iostream>
#include<unistd.h>
#include <sys/wait.h>

int main(){

    auto c_pid = fork();

    if(c_pid > 0){
        // parent context
        // parent process creates a new child process
        wait(NULL); // waiting for child process to be completed.
        std::cout << " Parent process done" << std::endl;
    }
    else if(c_pid == 0){
        // child context
        auto ret = execl ("/bin/ls", "ls", "-l", NULL);
        if (ret == -1)
            perror ("execl");
        std::cout << "ret " << ret << std::endl;
    }
    
    return 0;
}
