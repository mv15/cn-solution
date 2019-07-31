void print(int n)
{
    if(n <= 0)
    {
        return;
    }

    print(n - 1);

    cout << n << " ";

}

/*
// Main code

#include<iostream>
using namespace std;
#include "Solution.h"

int main(){
    int n;
    cin >> n;

    print(n);
}

*/
