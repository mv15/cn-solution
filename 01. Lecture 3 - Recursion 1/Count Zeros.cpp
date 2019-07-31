
int countZeros(int n) {
    // Write your code here
    if(n <= 9)
        return 0;

    int last = n % 10;

    if(last == 0)
        return 1 + countZeros(n / 10);

    return countZeros(n / 10);

}

/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}

*/



