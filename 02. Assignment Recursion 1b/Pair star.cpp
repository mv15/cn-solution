// Change in the given string itself. So no need to return or print the changed string.
#include<bits/stdc++.h>
using namespace std;

void pairStar(char input[]) {
    // Write your code here
    if(input[0] == '\0')
        return ;

    if(input[0] == input[1])
    {
        int len = strlen(input);

        for(int i = len; i >= 1; i--)
        {
            input[i + 1] = input[i];
        }

        input[1] = '*';
        pairStar(input + 2);
    }

    pairStar(input + 1);

}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}

*/
