node* append_LinkedList(node* head,int n)
{
    node* curr = head, *prev = NULL;

    int i = 1;

    while(curr -> next != NULL)
    {
        if(i < n)
            i++;
        else
        {
            if(prev == NULL)
                prev = head;
            else
                prev = prev -> next;
        }
        curr = curr -> next;
    }

    curr -> next = head;
    head = prev -> next;
    prev -> next = NULL;

    return head;
}

/*
// Main code

//Append the last n elements of a linked list to the front
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
#include "solution.h"
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}


*/
