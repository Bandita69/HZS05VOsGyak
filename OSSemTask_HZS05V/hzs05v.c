#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{


    pid_t child_pid, wpid;
    pid_t grandson_pid;
    int status = 0;
    
    int grandson = 4;


    printf("Fo procesz [Procesz id: %d].\n\n",getpid());

    
        
	child_pid = fork();
        if (child_pid > 0)
        {

            //szolo kod
        
    	   printf("\n szulo megszuletett [Procesz id: %d][Szulo Szulo Procesz id: %d].\n ",getpid(),getppid());
	

            for (int id2=0; id2<grandson; id2++)
            {
		
                grandson_pid = fork();
                if (grandson_pid > 0)
                {
			
                    //unoka kod
                    printf("\n(unoka)gyerek megszuletett [Procesz id: %d] [Szulo Procesz id: %d]-tol.\n ",getpid(),getppid());
			sleep(2);
                  }
 		}
 	      }


	child_pid = fork();
        if (child_pid > 0)
        {
            //szolo kod
        
    	   printf("\n szulo megszuletett [Procesz id: %d][Szulo Szulo Procesz id: %d].\n ",getpid(),getppid());
	

            for (int id2=0; id2<grandson; id2++)
            {
		
                grandson_pid = fork();
                if (grandson_pid > 0)
                {
			
                    //unoka kod
                    printf("\n(unoka)gyerek megszuletett [Procesz id: %d] [Szulo Procesz id: %d]-tol.\n ",getpid(),getppid());
			sleep(3);
                  }
 		}
 	      }



        printf("\n a gyerek megszuntek a [Szulo Procesz id: %d] most szunik meg.\n\n",getpid());


    


     // megvarja a nagyszulo a gyerekeket es csak azutan fut le:
    
    kill(child_pid, SIGKILL);
    printf("\n(nagy)szulo megszunt letezni [Procesz id: %d].\n",getpid());
}
