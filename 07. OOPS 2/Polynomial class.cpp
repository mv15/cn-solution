/*
int main()
{
    int count1,count2,choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }

    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }

    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;

        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

    }

    return 0;
}
*/

class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;

    // Complete the class

    Polynomial()  // Default Constructor
    {
      degCoeff = new int[5];
      capacity = 5;
      for(int i = 0; i < 5; i++)
      {
        degCoeff[i] = 0;
      }
    }

    Polynomial(Polynomial const &p)  // Copy Constructor
    {
       // Deep copy
       this -> degCoeff = new int[p.capacity];

       for(int i = 0; i < p.capacity; i++)
       {
          this -> degCoeff[i] = p.degCoeff[i];
       }
       this -> capacity = p.capacity;
    }

    void setCoefficient(int degree, int coefficient)
    {
        if(degree >= capacity)
        {
            int t = capacity;
            while(degree >= capacity)
                capacity *= 2;

            int* newArray = new int[capacity];

            for(int i = 0; i < capacity; i++)
            {
                newArray[i] = 0;
            }

            for(int i = 0; i < t; i++)
            {
                newArray[i] = degCoeff[i];
            }

            delete[] degCoeff;
            degCoeff = newArray;
        }
        degCoeff[degree] = coefficient;
    }

    Polynomial operator+(Polynomial const &p)
    {
       Polynomial p1;
       int minimum = min(capacity, p.capacity);
       int maximum = max(capacity, p.capacity);
       p1.degCoeff = new int[maximum];
       p1.capacity = maximum;

       for(int i = 0; i < maximum; i++)
       {
          p1.setCoefficient(i, 0);
       }

       for(int i = 0; i < minimum; i++)
       {
          int coeff = degCoeff[i] + p.degCoeff[i];
          p1.setCoefficient(i, coeff);
       }

       for(int i = minimum; i < maximum; i++)
       {
         if(maximum == capacity)
           p1.setCoefficient(i, degCoeff[i]);
         else
            p1.setCoefficient(i, p.degCoeff[i]);
       }
       return p1;
    }

    Polynomial operator-(Polynomial const &p)
    {
       Polynomial p1;
       int minimum = min(capacity, p.capacity);
       int maximum = max(capacity, p.capacity);
       p1.degCoeff = new int[maximum];
       p1.capacity = maximum;

       for(int i = 0; i < maximum; i++)
       {
          p1.setCoefficient(i, 0);
       }

       for(int i = 0; i < minimum; i++)
       {
          int coeff = degCoeff[i] - p.degCoeff[i];
          p1.setCoefficient(i, coeff);
       }

       for(int i = minimum; i < maximum; i++)
       {
         if(maximum == capacity)
           p1.setCoefficient(i, degCoeff[i]);
         else
            p1.setCoefficient(i, -1*p.degCoeff[i]);
       }
       return p1;
    }

    int getCoeff(int degree)
    {
        if(degree >= capacity)
            return 0;
        return degCoeff[degree];
    }

    Polynomial operator*(Polynomial const &p)
    {
       Polynomial p1;
       int minimum = min(capacity, p.capacity);
       int maximum = max(capacity, p.capacity);
       p1.degCoeff = new int[maximum + minimum];
       p1.capacity = maximum + minimum;

       for(int i = 0; i < p1.capacity; i++)
       {
          p1.setCoefficient(i, 0);
       }

       for(int i = 0; i < capacity; i++)
       {
           for(int j = 0; j < p.capacity; j++)
           {
               int coeff = p1.getCoeff(i+j) + (degCoeff[i] * p.degCoeff[j]);
               p1.setCoefficient(i + j, coeff);
           }
       }
       return p1;
    }

    void operator=(Polynomial const &p)
    {
      delete[] degCoeff;
      this -> degCoeff = new int[p.capacity];

       for(int i = 0; i < p.capacity; i++)
       {
          this -> degCoeff[i] = p.degCoeff[i];
       }
       this -> capacity = p.capacity;
    }


    void print()
    {
      for(int i = 0; i < capacity; i++)
      {
         if(degCoeff[i] != 0)
         cout << degCoeff[i] << "x" << i << " ";
      }
      cout << endl;
    }
};
