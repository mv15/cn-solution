class Deque
{
    int  *arr;
    int  front;
    int  rear;
    int  size;
    
    public :
  
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
        arr = new int[size];
    }
 
    void  insertFront(int key);
    void  insertRear(int key);
    void  deleteFront();
    void  deleteRear();
    bool  isFull();
    bool  isEmpty();
    int  getFront();
    int  getRear();
};
 
bool Deque::isFull()
{
    return ((front == 0 && rear == size-1)||
            front == rear+1);
}

bool Deque::isEmpty ()
{
    return (front == -1);
}

void Deque::insertFront(int key)
{
    if (isFull())
    {
        cout << "-1\n" << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = size - 1 ;
    else 
        front = front-1;
    arr[front] = key ;
}

void Deque ::insertRear(int key)
{
    if (isFull())
    {
        cout << "-1\n " << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == size-1)
        rear = 0;
    else
        rear = rear+1;
 
    arr[rear] = key ;
}
 
void Deque ::deleteFront()
{
    if (isEmpty())
    {
        cout << "-1\n" << endl;
        return ;
    }
 
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        if (front == size -1)
            front = 0;
 
        else
            front = front+1;
}
 
void Deque::deleteRear()
{
    if (isEmpty())
    {
        cout << "-1\n" << endl ;
        return ;
    }
 
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size-1;
    else
        rear = rear-1;
}
 
int Deque::getFront()
{
    if (isEmpty())
    {
        return -1 ;
    }
    return arr[front];
}
 
int Deque::getRear()
{
    if(isEmpty() || rear < 0)
    {
        return -1 ;
    }
    return arr[rear];
}

/*
// Main code

// C++ implementation of De-queue using circular
// array
#include<iostream>
using namespace std;

#include "Solution.h"

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}

*/
