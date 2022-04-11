#include <stdio.h>
#include <signal.h>
#include <unistd.h>



int main( int argc, char *argv[] )  {

   if( argc == 2 ) {
       system("./hsz05v_gyak9_12");
       kill(argv[1], SIGALRM);
   }
   else if( argc > 2 ) {
      printf("Too many arguments.\n");
   }
   else {
      printf("One argument expected.\n");
   }
}
