#include <iostream>
#include <string>
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

void printKeypad(int num, string output)
{
    if(num == 0)
    {
        cout << output << endl;
        return;
    }

    int lastdigit = num % 10;
    int smalldigit = num / 10;

    string s = get_string(lastdigit);
    int len = s.length();

    for(int i = 0; i < len; i++)
    {
        printKeypad(num / 10, s[i] + output);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */

    return printKeypad(num, "");
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

    printKeypad(num);

    return 0;
}

*/
