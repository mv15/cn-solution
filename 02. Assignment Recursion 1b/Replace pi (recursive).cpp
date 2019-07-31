// Change in the given string itself. So no need to return or print anything
#include<bits/stdc++.h>
using namespace std;

void replacePi(char input[]) {
	// Write your code here
    if(input[0] == '\0')
        return ;

    if(input[0] == 'p' && input[1] == 'i')
    {
        int len = strlen(input);
        for(int i = len - 1; i >= 0; i--)
        {
            input[i+2] = input[i];
        }

        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        replacePi(input + 4);
    }

    replacePi(input + 1);

}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

*/

