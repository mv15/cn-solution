#include <iostream>
#include <string>
using namespace std;

void printPermutations(string input, int start, int end)
{
    if(start == end)
    {
        cout << input << endl;
        return;
    }

    for(int i = start; i <= end; i++)
    {
        swap(input[start], input[i]);
        printPermutations(input, start + 1, end);
        swap(input[start], input[i]);
    }
}

void printPermutations(string input){
    printPermutations(input, 0, input.length() - 1);
}


/*
// Main code

#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}

*/
