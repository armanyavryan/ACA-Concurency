#include<iostream>
#include<unistd.h>
#include <sys/wait.h>

int main(){

    // parent process first child process
    auto c1_pid = fork();

    if(c1_pid > 0){
        // parent context

        // parent process forkes second child process
        auto c2_pid = fork();

        if(c2_pid == 0){
            // child 2 context
            // std::cout << " asssignment1 : running assignment0 - pid = " << getpid() << std::endl;
            auto ret = execl ("/bin/date", "date", NULL);
            if (ret == -1)
                perror ("execl");
            std::cout << "ret " << ret << std::endl;

        }
        else{
            wait(NULL);
        }
        wait(NULL);
        std::cout << "Parent process done" << std::endl;
    }
    else if(c1_pid == 0){
        // child 1 context
        auto ret = execl ("/bin/ls", "ls", "-l", NULL);
        if (ret == -1)
            perror ("execl");
        std::cout << "ret " << ret << std::endl;
    }

    return 0;
}
