int length(node* head)
{
  int count = 0;
  while(head != NULL)
  {
    count++;
    head = head -> next;
  }
  
  return count;
}

node* bubble_sort_LinkedList_itr(node* head)
{
   
  int len = length(head);
  
  for(int i = 0; i < len; i++)
  {
    node* curr = head, *prev = NULL, *next = NULL;
    while(curr -> next != NULL)
    {
       if(curr -> data > curr -> next -> data)
       {
         if(prev == NULL)
         {
           next = curr -> next;
           curr -> next = next -> next;
           next -> next = curr;
           prev = next;
           head = prev;
         }
         else
         {
           next = curr -> next;
           prev -> next = curr -> next;
           curr -> next = next -> next;
           next -> next = curr;
           prev = next;
         }
       }
       else 
       {
         prev = curr;
         curr = curr -> next;
       }
    }
  }
  
  return head;
  
}

/*
// Main code

//bubble sort iterative
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
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}

*/