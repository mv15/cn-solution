// arr - input array
// size - size of array
// d - array to be rotated by d elements

void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
  d = d % size;
  int i, k = 0;

  int* temp = new int[size];

  for(i = d; i < size; i++)
  {
    temp[k++] = arr[i];
  }

  for(i = 0; i < d; i++)
  {
    temp[k++] = arr[i];
  }

  for(i = 0; i < size; i++)
  {
    arr[i] = temp[i];
  }

  delete [] temp;

}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;

    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}

*/
