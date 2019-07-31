Node* deleteNode(Node *head, int i) {
    int count = 0;
    Node* temp = head;

    if(i == 0)
        return head -> next;

    while(temp != NULL && count < i - 1)
    {
        temp = temp -> next;
        count++;
    }

    if(temp -> next != NULL)
    {
        Node* d = temp -> next;
        temp -> next = temp -> next -> next;
        delete d;
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
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);
    return 0;
}

*/
