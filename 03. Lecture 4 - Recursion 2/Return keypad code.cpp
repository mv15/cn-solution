#include <bits/stdc++.h>
using namespace std;

string get_string(int n)
{
    if(n == 2)
        return "abc";
    if(n == 3)
        return "def";
    if(n == 4)
        return "ghi";
    if(n == 5)
        return "jkl";
    if(n == 6)
        return "mno";
    if(n == 7)
        return "pqrs";
    if(n == 8)
        return "tuv";
    if(n == 9)
        return "wxyz";

    return "";
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0)
    {
        output[0] = "";
        return 1;
    }

    int smallans = keypad(num / 10, output);

    string s = get_string(num % 10);
    int len = s.length();

    // for creating copies

    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < smallans; j++)
        {
            output[j + (i+1)*smallans] = output[j];
        }
    }

    int k = 0;

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < smallans; j++)
        {
            output[k] = output[k] + s[i];
       //     cout << output[k] << endl;
            k++;
        }
    }

    return len * smallans;
}

/*
// Main code

#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

*/
