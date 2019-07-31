class ans
{
  public:
  Node<int>* head;
  Node<int>* tail;
};

ans helper(BinaryTreeNode<int>* root)
{
  if(root == NULL)
  {
    ans temp;
    temp.head = NULL;
    temp. tail = NULL;
    return temp;
  }
  
  ans leftans = helper(root -> left);
  ans rightans = helper(root -> right);
  
  Node<int>* temp = new Node<int>(root -> data);
  
  ans f;
  
  if(leftans.head == NULL && rightans.head == NULL)
  {
    leftans.head = temp;
    leftans.tail = temp;
    rightans.head = temp;
    rightans.tail = temp;
  }
  else if(leftans.head == NULL && rightans.head != NULL)
  {
    leftans.head = temp;
    leftans.tail = temp;
    temp -> next = rightans.head;
  }
  else
  {
    leftans.tail -> next = temp;
    temp -> next = rightans.head;
  }
  
  f.head = leftans.head;
  f.tail = rightans.tail;
  
  return f;
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
  return helper(root).head;
}

/*
// Main code

#include <iostream>
#include <queue>

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
  q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    
}


*/