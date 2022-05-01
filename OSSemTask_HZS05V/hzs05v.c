#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    pid_t pid_par;
    pid_t pid;

    for (size_t i = 1; i <= 2; i++)
    {
        pid_par = fork();

        if (pid_par != 0)
        {
            printf("\n");
            wait(NULL);
            exit(0);
        }
        else
        {
            printf("\n");
            for (int i = 1; i <= 3; i++)
            {
                pid = fork();

                if (pid == 0)
                {
                    printf("Child process => PPID=%d, PID=%d\n", getppid(), getpid());
                    wait(0);
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

    
    printf("\nITT A VEGE");
   wait(NULL);
   wait(NULL);
    return(0);
}
