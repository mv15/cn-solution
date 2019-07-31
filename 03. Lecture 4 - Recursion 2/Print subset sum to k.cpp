#include<bits/stdc++.h>
using namespace std;

void printSubsetSumToK(int input[], int size, vector<int> v, int k)
{
    if(size == 0)
    {
        if(k == 0)
        {
            for(int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    printSubsetSumToK(input + 1, size - 1, v, k);
    v.push_back(input[0]);
    printSubsetSumToK(input + 1, size - 1, v, k - input[0]);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    vector<int> v;
    printSubsetSumToK(input, size, v, k);
}

/*
// Main code

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}

*/
