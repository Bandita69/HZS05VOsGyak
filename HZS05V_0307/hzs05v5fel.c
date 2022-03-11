#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main () {

		int pid = fork();
		if ( pid == 0 )
		 {
			exit(999);

		 }

		int status;
		waitpid(pid, &status, 0);

		if ( WIFEXITED(status)) {

		int exit_status = WEXITSTATUS(status);
		printf("Exit kod: %d\n", exit_status);
		}
return(0);

}
