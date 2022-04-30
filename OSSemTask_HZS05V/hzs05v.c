#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>


int main()
{


    pid_t child_pid, wpid;
    pid_t grandson_pid;
    int status = 0;
    int parent = 2;
    int grandson = 3;

//nagyszulo kod
    printf("(nagy)szulo megszuletett  [Procesz id: %d].\n\n",getpid());

    for (int id=0; id<parent; id++)
    {
        sleep(1);

        if ((child_pid = fork()) == 0)
        {


            //szolo kod
            printf("(szulo)gyerek megszuletett [Procesz id: %d][Szulo Procesz id: %d].\n ",getpid(),getppid());
            sleep(1);

            for (int id2=0; id2<grandson; id2++)
            {
                sleep(1);
                if ((grandson_pid = fork()) == 0)
                {
                    //unoka kod
                    printf("\n(unoka)gyerek megszuletett [Procesz id: %d] [Szulo Procesz id: %d]-tol.\n ",getpid(),getppid());
                    kill(grandson_pid, 0);
                    sleep(1);


                    exit(0);


                }

            }

            exit(0);

        }

        while ((wpid = wait(&status)) > 0);
        printf("\n(szulo)gyereket megszuntette a [Szulo Procesz id: %d].\n\n",getpid());


    }


    while ((wpid = wait(&status)) > 0); 

    // megvarja a nagyszulo a gyerekeket es csak azutan fut le:
    
    kill(child_pid, SIGKILL);
    printf("\n(nagy)szulo megszunt letezni [Procesz id: %d].\n",getpid());
}
