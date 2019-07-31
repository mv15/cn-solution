/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don�t print the subsets, just save them in output.
***/

#include<bits/stdc++.h>
using namespace std;
int m = 0;

void subsetSumToK(int input[], int n, vector<int> v, int output[][50], int k)
{
    if(n == 0)
    {
        if(k == 0)
        {
            output[m][0] = v.size();
            for(int i = 0; i < v.size(); i++)
            {
                output[m][i+1] = v[i];
            }
            m++;
        }
        return;
    }

    subsetSumToK(input + 1, n - 1, v, output, k);
    v.push_back(input[0]);
    subsetSumToK(input + 1, n - 1, v, output, k - input[0]);
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    vector<int> v;
    subsetSumToK(input, n, v, output, k);
    return m;
}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;

  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) {
	for( int j = 1; j <= output[i][0]; j++) {
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

*/
