#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){


	int pip[2];
	pid_t p;

	if (pipe(pip) == -1){
	fprintf(stderr, "Snake? Snake! Snakeee!!");
	return 1;
	}

	p = fork();

	if (p<0){
	fprintf(stderr, "A villas reggeli nem jott ossze");
	return 1;
	}
	// Szuloi felugyelet
	else if (p > 0){

	char szoveg[100];
	
	wait(NULL);
	close(pip[1]);
	
	read(pip[0], szoveg, 100);
	printf("Meg nem veszithetek : %s", szoveg);
	close(pip[0]);
	}

	// gyerek szabadsag
	else {
	
		
	close(pip[0]);
	write(pip[1], "Meg elni akarok!\n", strlen("Meg elni akarok!\n"));
	close(pip[1]);
	}

	return(0);
	}
