#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(){

	FILE *rd_s,*wr_s;
	int c_status, ret_value;
	char char_ptr[32];
	size_t n_elemek;
	char str[] = "hzs05v";
	pid_t pid;	
	char fifoname[] = "fifi.fifo";

	if((pid = fork()) < 0){
	perror("Bajvan");
	exit(2);
	}

	//gyerek szabadsag
	if (pid == (pid_t)0) {
		wr_s = fopen(fifoname,"w");
		n_elemek = fwrite(str,1,strlen(str),wr_s);	
	exit(0);

	}
	//szuloi felugyelet
	else{
	rd_s = fopen(fifoname,"r");
	ret_value = fread(char_ptr,sizeof(char),strlen(str),rd_s);
	
	 wait(NULL);
	}
	printf("vege\n");
	return(0);
	}
