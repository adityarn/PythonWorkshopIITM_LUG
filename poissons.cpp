#include <ctime>
#include<iostream>
#include<vector>
#include<complex>
#include<stdio.h>
using namespace std;

int main()
{
  clock_t begin = clock();  
  vector < vector < double > > array;
  int n = 10000;
  array.resize(n);
  for(int i=0; i<n; i++)
    array[i].resize(n);
  
  /*setting initial values */
  for(int j=0; j<n; j++)
    for(int k=0; k<n; k++)
      array[j][k] = 0.0;

  /*setting BC */
  for(int j=0; j<n; j++)
    array[j][0] = 1.0;

  int counter = 0;
  while(counter < 10)
    {
      for(int i=1; i<n-1; i++)
	{
	  for(int j=1; j<n-1; j++)
	    {
	      array[i][j] = (array[i][j+1] + array[i][j-1] + array[i+1][j] + array[i-1][j]) * 0.25;
	    }
	    
	}
      counter+=1;
    }

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout<<"\n elapsed time = "<<elapsed_secs<<"\n \n";

  return 1;
}
