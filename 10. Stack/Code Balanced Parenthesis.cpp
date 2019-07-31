#include<bits/stdc++.h>
using namespace std;

bool checkBalanced(char *exp) {
	// Write your code here
    stack<char> s;
    
    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
            s.push(exp[i]);
        else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if(s.empty())
                return false;
            
            char ch = s.top();
            s.pop();
            
            if(ch == '{' && exp[i] == '}')
                continue;
            else if(ch == '[' && exp[i] == ']')
                continue;
            else if(ch == '(' && exp[i] == ')')
                continue;
            else
                return false;
        }
    }
    
    if(s.empty())
        return true;
    
    return false;
}