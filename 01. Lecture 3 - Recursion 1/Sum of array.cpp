int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

    int total = 0;

    for(int i = 0; i < n; i++)
    {
        total += input[i];
    }

    return total;

}

/*
// Sum of array

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

    cout << sum(input, n) << endl;
}


*/
