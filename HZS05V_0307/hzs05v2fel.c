#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	char str[10];

	printf( "Enter a command\n" );
	fgets(str, 20, stdin);
	system(str);
	return(0);

}
