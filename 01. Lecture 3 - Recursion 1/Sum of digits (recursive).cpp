int sumOfDigits(int n) {
    // Write your code here
    if(n == 0)
        return 0;

    return n % 10 + sumOfDigits(n / 10);

}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}

*/
