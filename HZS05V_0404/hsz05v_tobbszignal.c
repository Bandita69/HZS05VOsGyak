#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigquit_handler(int signum)
{
	printf("\n Jonapot:  %d\n",signum);
}

void sigint_handler(int signum)
{
	printf("\nNemsikerult!: %d\n",signum);
	signal(SIGINT,SIG_DFL);
}


int main () 
{
	signal(SIGQUIT, sigquit_handler);
	signal(SIGINT, sigint_handler);

	for(int i=1;;i++)
	{
	printf("%d telik az ido\n",i);
	sleep(2);
	}

	return(0);
}
