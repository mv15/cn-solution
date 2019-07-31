Node* mergeTwoLLs(Node *head1, Node *head2) {
    Node* finalhead = NULL, *finaltail = NULL;
    
    if(head1 -> data <= head2 -> data)
    {
        finalhead = head1;
        finaltail = head1;
        head1 = head1 -> next;
    }
    else
    {
        finalhead = head2;
        finaltail = head2;
        head2 = head2 -> next;
    }
    
    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> data <= head2 -> data)
        {
            finaltail -> next = head1;
            finaltail = head1;
            head1 = head1 -> next;
        }
        else
        {
            finaltail -> next = head2;
            finaltail = head2;
            head2 = head2 -> next;
        }
    }
    
    if(head1 != NULL)
        finaltail -> next = head1;
    
    if(head2 != NULL)
        finaltail -> next = head2;
    
    
    return finalhead;
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
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}


*/