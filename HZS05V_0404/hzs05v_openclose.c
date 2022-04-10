#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
int main () {
	
	int olvasott_bytek, fp, pointer;
	char *buffer = (char *) calloc(100, sizeof(char));
	
	fp = open("hzs05v.txt", O_RDWR);
	if (fp < 0)
	{
	perror("bajvan");
	exit(1);
	}

	//3-al ter vissza ha rendben megnyilt 0,1,2 az std: in out err
	printf("Megnyilt = %d \n",fp);
	
	olvasott_bytek = read(fp, buffer, 30);
	
	printf("Beolvasott bytek szama (read): %d \n", olvasott_bytek);


	olvasott_bytek = write(1, "Beolvasott bytek szama (write): %d \n", strlen("Beolvasott bytek szama (write): %d \n"));
	printf("Beolvasott bytek szama (write): %d \n", olvasott_bytek);

	
	pointer = lseek(fp,0,SEEK_SET);
	printf("Most ennel a pozicional van a pointer %d\n", pointer);
	read(fp,buffer,pointer);
	write(1,buffer,olvasott_bytek);
	
	if (close(fp) < 0)
	{
	perror("ajjajj");
	exit(1);
	}
	return(0);

}
