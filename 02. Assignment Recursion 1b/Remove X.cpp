// Change in the given string itself. So no need to return or print anything
#include<bits/stdc++.h>
using namespace std;

void removeX(char input[]) {
    // Write your code here

    if(input[0] == '\0')
        return;

    if(input[0] == 'x')
    {
        int len = strlen(input);

        for(int i = 0; i < len; i++)
        {
            input[i] = input[i + 1];
        }

        removeX(input);
    }

    removeX(input + 1);
}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}

*/
