#include <stdio.h>
#include <stdlib.h>
#include "gcd.h"



/* Imperative style modification of example 1.20  */

    int gcdI(int i, int j) {
       while ( i != j) {
         printf("times2\n");
           if (i > j) {
              i = i - j;
           } else {
              j = j - i;
           }
       }
       return i;
    }

/* Modiification of 1.4 page 38 */
  int  gcdM(int i, int j) {
     while ( i != j) {
        if (i > j) {
           i = i % j;
        } else {
            j = j % i;
        }
     }
   return i;

 }
/* ADD code for the recursive style implementation*/
int  gcdF(int i, int j)
{
  printf("times1\n");
  if (i > j) {
    if(i%j==0)
    {
      return j;
    }
    return gcdF(i % j,j);
  }
  else {
    if(j%i==0)
    {
      return i;
    }
    return gcdF(i,j%i);
  }
}
/*  Also
  For exercise 4 modify the main function to call gcdR instead of gcdI
*/
int main(int argc, char **argv) {
  if (argc < 3) {
    printf("%s usage: [I] [J]\n", argv[0]);
    return 1;
  }
  int i = atoi(argv[1]);
  int j = atoi(argv[2]);
  int r = gcdF(i,j);
  printf("%d\n", r);
  return 0;
}
