#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t pid_par = fork();

    if (pid_par != 0)
    {
        printf("szulo\n");
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
    else
    {
        wait(NULL);
      
    }

    return EXIT_SUCCESS;
}