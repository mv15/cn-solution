#include <string.h>
using namespace std;

void printAllPossibleCodes(string input, int n, string temp)
{
    if(n < -1)
        return;

    if(n == -1)
    {
        cout << temp << endl;
        return;
    }

    int one_digit = input[n] - '0';

    string temp1 = (char)('a' + one_digit - 1) + temp;

    printAllPossibleCodes(input, n - 1, temp1);

    int last_digit;

    if(n >= 1)
        last_digit = (input[n-1] - '0') * 10 + one_digit;

    if(last_digit <= 26 && last_digit > 9)
    {
        string temp2 = (char)('a' + last_digit - 1) + temp;
        printAllPossibleCodes(input, n - 2, temp2);
    }
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    printAllPossibleCodes(input, input.length() - 1, "");
}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}

*/
