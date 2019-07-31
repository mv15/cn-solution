node* skipMdeleteN(node *head, int M, int N) {
    if(head == NULL)
        return NULL;
    
    node *temp = head;
    
    while(temp != NULL)
    {
        for(int i = 1; i < M && temp != NULL; i++)
        {
            temp = temp -> next;
        }
        
        if(temp == NULL)
            return head;
        
        node *t = temp -> next;
        
        for(int i = 0; i < N && t != NULL; i++)
        {
            t = t -> next;
        }
        
        temp -> next = t;
        temp = t;
    }
    
    return head;

}

/*
// Main code

//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
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
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}

*/