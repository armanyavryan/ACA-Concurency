#include<iostream>
#include<unistd.h>
#include <sys/wait.h>

int main(){

    auto c_pid = fork();

    if(c_pid > 0){
        // parent context
        // parent process forkes new child process
        wait(NULL);
        std::cout << "Parent process done" << std::endl;
    }
    else if(c_pid == 0){
        // childs context
        auto ret = execl ("/bin/echo", "echo", "Hello from the child process", NULL);
        if (ret == -1)
            perror ("execl");
        std::cout << "ret " << ret << std::endl;
    }
    
    return 0;
}








