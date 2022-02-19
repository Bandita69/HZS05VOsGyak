#include <stdio.h>

int main () {
   FILE *fp;
   char buff[255];

   fp = fopen("timko.txt", "w+");

   fputs("Timko Andras Gazdasaginformatikus HZS05V", fp);

   fgets(buff, 255, (FILE*)fp);

   fclose(fp);

   return(0);
}
