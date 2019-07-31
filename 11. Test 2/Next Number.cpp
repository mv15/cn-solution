int getcarry(Node *head)
{
    if(head == NULL)
        return 1;
    
    int ans = head -> data + getcarry(head -> next);
    
    head -> data = ans % 10;
    return ans / 10;
}


Node* NextLargeNumber(Node *head) {    
    int carry = getcarry(head);
    
    if(carry)
    {
        Node* newnode = new Node(carry);
        newnode -> next = head;
        head = newnode;
    }
    
    return head;
}

/*
// Main code

#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
#include "Solution.h"

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}

*/