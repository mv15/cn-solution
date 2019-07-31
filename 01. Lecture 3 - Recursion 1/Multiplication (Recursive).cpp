int multiplyNumbers(int m, int n) {
    // Write your code here

    if(n == 0)
        return 0;

    return m + multiplyNumbers(m, n - 1);

}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}

*/


