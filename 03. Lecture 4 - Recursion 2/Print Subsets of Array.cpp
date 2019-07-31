#include<bits/stdc++.h>
using namespace std;

void printSubsetsOfArray(int input[], int size, vector<int> v)
{
    if(size == 0)
    {
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }

    printSubsetsOfArray(input + 1, size - 1, v);
    v.push_back(input[0]);
    printSubsetsOfArray(input + 1, size - 1, v);
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    vector<int> v;

    printSubsetsOfArray(input, size, v);

}

/*
// Main code

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}

*/
