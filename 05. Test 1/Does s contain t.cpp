bool checksequenece(char large[] , char*small) {
    if(small[0] == '\0')
        return true;

    if(large[0] == '\0')
        return false;

    if(small[0] == large[0])
        return checksequenece(large + 1, small + 1);

    return checksequenece(large + 1, small);
}

/*
// Main code

#include<iostream>
using namespace std;
#include "solution.h"

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}

*/
