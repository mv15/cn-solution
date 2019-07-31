class ComplexNumbers {
    // Complete this class
    int real;
    int imag;

    public:

    ComplexNumbers(int real, int imag)
    {
        this -> real = real;
        this -> imag = imag;
    }

    void plus(ComplexNumbers c)
    {
        this -> real += c.real;
        this -> imag += c.imag;
    }

    void multiply(ComplexNumbers c)
    {
        int r , i;
        r = (this -> real * c.real) - (this -> imag * c.imag);
        i = (this -> real * c.imag) + (this -> imag * c.real);
        this -> real = r;
        this -> imag = i;
    }

    void print()
    {
        cout << real << " + i" << imag << endl;
    }

};


/*
// Main code

#include <iostream>
using namespace std;
#include "ComplexNumbers.h"

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
}
*/
