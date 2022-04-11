#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int signum)
{
	printf("\nIsten Hozott Neptunkod: %d\n",signum);
	
}


int main () 
{
	signal(SIGINT, sig_handler);
	
	pause();

	return(0);
}
