// arr - input array
// size - size of array
// x - sum of triplets
#include<bits/stdc++.h>
using namespace std;

void FindTriplet(int input[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */

    sort(input, input + size);

    for(int m = 0; m < size; m++)
    {
        int temp = x - input[m];

        int start = m + 1, end = size - 1;

        // Pair sum in an array
        while(start < end)
        {
            if(input[start] + input[end] == temp)
            {
                if(input[start] == input[end])
                {
                    int n = end - start + 1;
                    int count = (n*(n-1)) / 2;

                    while(count > 0)
                    {
                        cout << input[m] << " " << input[start] << " " << input[end] << endl;
                        count--;
                    }
                    start = end;
                }
                else
                {
                    int i = start, leftcount = 0;

                    while(input[i] == input[start] && i < end)
                    {
                        i++;
                        leftcount++;
                    }

                    int j = end, rightcount = 0;

                    while(input[j] == input[end] && i > start)
                    {
                        j--;
                        rightcount++;
                    }

                    start = i;
                    end = j;

                    int count = leftcount * rightcount;

                    while(count > 0)
                    {
                        cout << input[m] << " " << input[start - 1] << " " << input[end + 1] << endl;
                        count--;
                    }
                }
            }
            else if(input[start] + input[end] < temp)
                start++;
            else
                end--;
        }
    }

}

/*
// Main code

#include <iostream>
using namespace std;
#include "solution.h"

int main() {

	int size;

	int x;
	cin>>size;

	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);

	return 0;
}


*/
