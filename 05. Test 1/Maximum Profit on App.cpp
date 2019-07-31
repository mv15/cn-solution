#include<bits/stdc++.h>
using namespace std;

int maximumProfit(int budget[], int n) {
    // Write your code here

    sort(budget, budget + n);

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int price = budget[i];
        price *= (n - i);
        if(ans < price)
            ans = price;
    }

    return ans;

}

/*
// Main code

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];

    cout << maximumProfit(input, n) << endl;

}

*/
