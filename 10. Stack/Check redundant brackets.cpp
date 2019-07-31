#include<stack>

bool checkRedundantBrackets(char *input) {
	// Write your code here
    stack<char> s;
    bool ans = true;
    
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] != ')')
            s.push(input[i]);
        else
        {
            char top = s.top();
            s.pop();
            ans = true;
            
            while(top != '(')
            {
                ans = false;
                top = s.top();
                s.pop();
            }
            if(ans == true)
                return true;
        }
    }
    
    return false;
}

/*
// Main code

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

}

*/