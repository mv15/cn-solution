void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/

    if(input[0] == '\0')
        return;

    if(input[0] == input[1])
    {
        int i;
        for(i = 1; input[i] != '\0'; i++)
        {
            input[i-1] = input[i];
        }
        input[i-1] = '\0';
        return removeConsecutiveDuplicates(input);
    }

    return removeConsecutiveDuplicates(input + 1);
}

/*
// Main code

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}

*/
