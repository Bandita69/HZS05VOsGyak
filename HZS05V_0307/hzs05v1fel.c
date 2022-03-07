#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	char vegrehajto[20];
	
	strcpy( vegrehajto, "ls -l" );
	system(vegrehajto);

	return(0);

}
