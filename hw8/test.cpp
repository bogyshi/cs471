#include<iostream>

using namespace std;
int main()
{
  double* dp = new double(3);
  void* vp;
  int* ip;
	//which of the following assignments does the compiler complain about?

  vp = dp;
  //dp = vp; // invalid conversion from void pointer tp double *
  //ip = dp; //cannot convert double to int *
  //dp = ip; //cannot convert int * to double *
  //ip = vp; //invalid concersion from void * to int *
  
  ip = (int*) vp;
  cerr<<*ip;
  ip = static_cast<int*>(vp);
  cerr<<*ip;
  //ip = static_cast<int*>(dp); //invalid static cast from type double * to int *
  ip = reinterpret_cast<int*>(dp);
  cerr<<*ip;
  int n = 4;
  //double *a[n]; //a is an n element array of pointers to integers , Programming language pragmatics page 386
  double (*b)[n]; //b is a pointer to an n element array of integers, programming language pragmantics page 386
  double (*c[n])(); 
  double (*d())[n];
  //cerr<<typeof(c);

   const int k = 3; // you need to figure out the value of ???
   int * i = 0;
   struct A {
     int x[k];
   };
   A* a = 0;
   printf( "%d  %d  %d %d  %d  %d  \n",
	   i+1, i+k, k, a+k, &(a[9]), &(a[9]) - (a+1)  );
   cerr<<sizeof(A);
}
