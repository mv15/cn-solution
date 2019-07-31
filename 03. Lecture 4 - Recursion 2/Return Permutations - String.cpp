#include <string>
using namespace std;

int m = 0;

void returnPermutations(string input, int start, int end, string output[])
{
    if(start == end)
    {
        output[m++] = input;
        return;
    }

    for(int i = start; i <= end; i++)
    {
        swap(input[start], input[i]);
        returnPermutations(input, start + 1, end, output);
        swap(input[start], input[i]);
    }
}


int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    returnPermutations(input, 0, input.length() - 1, output);
    return m;
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
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

*/
