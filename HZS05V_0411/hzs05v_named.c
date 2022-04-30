#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){

	
	int pip;	
	pid_t p;
	char * fifo = "./fifo";
	mkfifo(fifo, 0666);

	

	p = fork();

	if (p<0){
	fprintf(stderr, "A villas reggeli nem jott ossze");
	return 1;
	}
	// Szuloi felugyelet
	else if (p > 0){
	
	char szoveg[100];
	printf("felnott vagyok varok\n");
	wait(NULL);
	printf("felnott vagyok nem varok\n");
	pip = open(fifo, O_RDONLY);
	
	read(pip, szoveg, 100);
	printf("Meg nem veszithetek : %s", szoveg);
	close(pip);
	}

	// gyerek szabadsag
	else {
	printf("gyerek vagyok\n");
	pip = open(fifo, O_WRONLY);
	
	write(pip, "Meg elni akarok!\n", strlen("Meg elni akarok!\n"));
	
	close(pip);
	}

	return(0);
	}
