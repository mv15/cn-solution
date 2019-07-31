void printLevelATNewLine(BinaryTreeNode<int> *root) {
    // Write your code here
  if(root == NULL)
     return;
  
  queue<BinaryTreeNode<int>*> pending;
  pending.push(root);
  
  cout << root -> data << endl;
  
  while(pending.size() != 0)
  {
    int count = pending.size();
    
    while(count)
    {
    
       BinaryTreeNode<int>* temp = pending.front();
    
       if(temp -> left != NULL)
       {
         cout << temp -> left -> data ;
       }
       
       if(temp -> left != NULL)
         cout << " " ;
       
       if(temp -> right != NULL)
       { 
         cout << temp -> right -> data ;     
         cout << " " ;
       }
           
       if(temp -> left != NULL)
         pending.push(temp -> left);
       
       if(temp -> right != NULL)
         pending.push(temp -> right);
      
       pending.pop();
       count--;
    }
    
    cout << endl;
  }
}

/*
// Main code

#include <iostream>
#include <queue>

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
    printLevelATNewLine(root);
}


*/