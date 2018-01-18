#include <stdio.h>
#include "gcd.h"


/* Imperative style modification of example 1.20  */
int gcdI(int i, int j) {
  while ( i != j) { 
    if (i > j) {
      i = i - j;
    } else {
      j = j - i;
    }
  }      
  return i;
}

int gcdM(int i, int j) {
  while ( i != j) {
    if (i > j) {
       if(i%j==0)
	{
	  return j;
	}
      i = i % j;
    } else {
      if(j%i==0)
	{
	  return i;
	}
      j = j % i;
    }
  }
  return i;
} 

int main()
{
  int i = 1;
  int j = 1;
  while(i<100)
    {
      j=1;
      while(j<100)
	{
	  if(gcdI(i,j)==gcdM(i,j)){
	    printf("nice\n");
	    fflush(stdout);
	  }
	  else
	    printf("wut\n");
	  j++;
	}
      i++;
    }
}

