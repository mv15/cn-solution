// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array

void intersection(int input1[], int input2[], int size1, int size2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
  int* a = new int[1000001];
  int* b = new int[1000001];

  for(int i = 0; i < size1; i++)
  {
    a[input1[i]]++;
  }

  for(int i = 0; i < size2; i++)
  {
    b[input2[i]]++;
  }

  for(int i = 1; i < 1000001; i++)
  {
    for(int j = 0; j < min(a[i],b[i]); j++)
    {
      cout << i << "\n";
    }
  }

}

/*

// Main code

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#include "solution.h"

int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];

	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];

	for(int i=0;i<size2;i++)
		cin>>input2[i];


	intersection(input1,input2,size1,size2);


	return 0;
}

*/
