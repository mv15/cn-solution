#include<bits/stdc++.h>
using namespace std;

bool helper(char input[], int start, int end)
{
    if(start >= end)
        return true;

    if(input[start] != input[end])
        return false;

    return helper(input, start + 1, end - 1);
}

bool checkPalindrome(char input[]) {
    // Write your code here

    return helper(input, 0, strlen(input) - 1);
}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[50];
    cin >> input;

    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

*/

