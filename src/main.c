#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main1.h"
#include "main2.h"


int main(int argc, char const *argv[])
{
    int i;
    for(i = 0; i < 3; i++)
    {
       pid_t pid = fork();
       if(pid == 0)
            break; 
    }

    if(i == 0)//子进程1
    {
        while(1)
        {
           main1(); 
        }
        
        _exit(-1);
    }
    else if(i == 1)//子进程2
    {
        sleep(1);
        main2();
        _exit(-1);
    }
    else if(i == 2)//子进程3
    {

    }
    else if(i == 3)//父进程
    {
        while(1)
        {
            pid_t pid = waitpid(-1, NULL, WNOHANG);
            if(pid < 0)
                break;
        }
    }
    
    return 0;
}
