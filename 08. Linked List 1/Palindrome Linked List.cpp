node* reverse(node* head)
{
    if(head == NULL || head -> next == NULL)
        return head;

    node* smallans = reverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return smallans;
}

bool check_palindrome(node* head)
{
    node* slow = head, *fast = head;

    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    node* rev = reverse(slow);

    while(rev != NULL && head != NULL)
    {
        if(rev -> data == head -> data)
        {
            rev = rev -> next;
            head = head -> next;
        }
        else
            return false;
    }

    return true;
}

/*
// Main code

//Check if a linked list is a palindrome
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
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else
        cout << "false";
    return 0;
}

*/
