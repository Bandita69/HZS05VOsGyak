#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void sigchld_handler(int signum)
{
    pid_t pid;
    int   status;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        unregister_child(pid, status);   // Or whatever you need to do with the PID
    }
}

int main(void)
{
    
    signal(SIGINT,sigchld_handler);
    for (size_t i = 1; i <= 2; i++)
    {
        pid_t pid_par = fork();

        if (pid_par != 0)
        {
            printf("\n");
            exit(0);
            
            
        }
        else
        {
            printf("\n");
            for (int i = 1; i <= 3; i++)
            {
                pid_t pid = fork();

                if (pid == 0)
                {
                    printf("Child process => PPID=%d, PID=%d\n", getppid(), getpid());
                    exit(0);
                }
                else
                {
                    printf("Parent process => PID=%d\n", getpid());
                    printf("Waiting for child processes to finish...\n");
                    wait(NULL);
                    printf("child process finished.\n");
                   

                }
            }
            
            
        }
    }
    //int vege = kill(pid_par, SIGTERM);
    return EXIT_SUCCESS;
}