#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main () {

		FILE *pf = fopen("nemletezik.txt","r");
		if (pf == NULL) {
fprintf(stderr, "hiba a file megnyitasaval\n");
abort();
}
return(0);

}
