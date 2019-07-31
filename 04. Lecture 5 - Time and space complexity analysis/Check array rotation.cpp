// arr - input array
// n - size of array

int FindSortedArrayRotation(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

  for(int i = 1; i < n; i++)
  {
    if(arr[i] < arr[i-1])
      return i;
  }

  return 0;
}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	cout<<FindSortedArrayRotation(input,size);

	return 0;

}

*/
