bool helper(int *input, int size, int firstgroup, int secondgroup)
{
    if(size == 0)
        return firstgroup == secondgroup;

    if(input[0] % 5 == 0)
        return helper(input + 1, size - 1, firstgroup + input[0], secondgroup);

    if(input[0] % 3 == 0)
        return helper(input + 1, size - 1, firstgroup, secondgroup + input[0]);

    bool ans1 = helper(input + 1, size - 1, firstgroup + input[0], secondgroup);
    bool ans2 = helper(input + 1, size - 1, firstgroup, secondgroup + input[0]);

    return ans1 || ans2;
}

bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    int firstgroup = 0, secondgroup = 0;

    return helper(input, size, firstgroup, secondgroup);

}


/*
// Main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }


	return 0;

}

*/
