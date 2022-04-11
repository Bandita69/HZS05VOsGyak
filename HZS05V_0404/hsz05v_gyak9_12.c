#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void sig_handler(int signum)
{
	printf("\nIsten Hozott Neptunkod: %d\n",signum);
	
}


int main () 
{
	signal(SIGALRM, sig_handler);
	
	system("pause");

	return(0);
}
