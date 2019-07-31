#include<stack>

int countBracketReversals(char input[]){
	// Write your code here
    
    int length = 0;
    
    for(int i = 0; input[i] != '\0'; i++)
    {
        length += 1;
    }
    
    if(length == 0)
        return 0;
    
    if(length % 2 != 0)
        return -1;
    
    stack<char> s;
    
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] == '{')
            s.push(input[i]);
        else
        {
            if(!s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(input[i]);
        }
    }
    
    int ans = 0;
    
    while(!s.empty())
    {
        char ch1 = s.top();
        s.pop();
        char ch2 = s.top();
        s.pop();
        
        if(ch1 != ch2)
            ans += 2;
        else
            ans += 1;
    }
    
    return ans;
}

/*
// Main code

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}

*/