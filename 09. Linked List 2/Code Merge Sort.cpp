node* mergeTwoLLs(node *head1, node *head2) {
    node* finalhead = NULL, *finaltail = NULL;
    
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

node* mergeSort(node *head) {
    
    if(head == NULL || head -> next == NULL)
        return head;
    
    node *slow = head, *fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    node *head1 = head;
    node *head2 = slow -> next;
    slow -> next = NULL;
    
    node *smallans1 = mergeSort(head1);
    node *smallans2 = mergeSort(head2);
    
    node *ans = mergeTwoLLs(smallans1, smallans2);
    return ans;
}

/*
// Main code

//merge sort recursive
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
    head= mergeSort(head);
    print(head);
    return 0;
}

*/