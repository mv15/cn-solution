#include<bits/stdc++.h>
using namespace std;

int partition(int input[], int start, int end)
{
    int pivotelement = input[start];
    int count = 0;

    for(int i = start + 1; i <= end; i++)
    {
        if(input[i] <= pivotelement)
            count++;
    }

    int pivotindex = start + count;

    swap(input[start], input[pivotindex]);

    int i = start, j = end;

    while(i <= pivotindex && j >= pivotindex)
    {
        while(input[i] <= pivotelement)
            i++;

        while(input[j] > pivotelement)
            j--;

       if(i < pivotindex && j > pivotindex)
          swap(input[i++], input[j--]);
    }

    return pivotindex;
}


void quickSort(int input[], int start, int end)
{
    if(start >= end)
        return;

    int pivot = partition(input, start, end);
    quickSort(input, start, pivot - 1);
    quickSort(input, pivot + 1, end);
}

void quickSort(int input[], int size)
{
    return quickSort(input, 0, size - 1);
}

/*
// Main code

#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}


*/
