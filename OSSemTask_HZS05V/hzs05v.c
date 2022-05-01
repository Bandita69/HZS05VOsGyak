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
                    printf("Gyerek procesz => PPID=%d, PID=%d\n", getppid(), getpid());
                    //wait(0);
                    exit(0);
                    
                }
                else
                {
                    printf("Szulo procesz => PID=%d\n", getpid());
                    printf("Varok hogy a gyerek befejezze...\n");
                    wait(NULL);
                    printf("a gyerek procesz befejezte.\n");
                    
                }
            }
            
        }
    }

    
   printf("\nSzulo proceszek befejeztek.\n");
   //megvarja mig mind a ket szulo befejezi
   wait(NULL);
   return(0);
}
