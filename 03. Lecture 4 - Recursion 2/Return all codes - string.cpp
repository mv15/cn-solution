#include <bits/stdc++.h>
using namespace std;

int m = 0;

void getCodes(string input, int n, string output[10000], string temp)
{
    if(n < -1)
        return;

    if(n == -1)
    {
        output[m] = temp;
        m++;
        return;
    }

    int one_digit = input[n] - '0';

    string temp1 = (char)('a' + one_digit - 1) + temp;

    getCodes(input, n - 1, output, temp1);

    int last_digit;

    if(n >= 1)
        last_digit = (input[n-1] - '0') * 10 + one_digit;

    if(last_digit <= 26 && last_digit > 9)
    {
        string temp2 = (char)('a' + last_digit - 1) + temp;
        getCodes(input, n - 2, output, temp2);
    }
}

int getCodes(string input, string output[10000]) {

    getCodes(input, input.length() - 1, output, "");
    return m;
}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

*/
