#include<bits/stdc++.h>
using namespace std;

int stringToNumber(char input[]) {
    // Write your code here
    if(input[0] == '\0')
        return 0;

    int ans = stringToNumber(input + 1);

    return (input[0] - '0') * pow(10, strlen(input) - 1) + ans;

}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}

*/
