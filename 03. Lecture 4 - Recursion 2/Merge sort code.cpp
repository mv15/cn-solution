
void merge(int input[], int start, int end)
{
    int* temp = new int[end - start + 1];

    int mid = (start + end) / 2;
    int i = start, j = mid + 1;
    int k = 0;

    while(i <= mid && j <= end)
    {
        if(input[i] < input[j])
            temp[k++] = input[i++];
        else
            temp[k++] = input[j++];
    }

    while(i <= mid)
        temp[k++] = input[i++];

    while(j <= end)
        temp[k++] = input[j++];

    k = 0;

    for(int i = start; i <= end; i++)
    {
        input[i] = temp[k++];
    }

    delete [] temp;
}

void mergeSort(int input[], int start, int end)
{
    if(start >= end)
      return ;

    int mid = (start + end) / 2;

    mergeSort(input, start, mid);
    mergeSort(input, mid + 1, end);
    merge(input, start, end);
}

void mergeSort(int input[], int size){
	// Write your code here
    return mergeSort(input, 0, size - 1);

}


/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}

*/
