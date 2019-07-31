void printLevelWise(BinaryTreeNode<int> *root)
{
  queue<BinaryTreeNode<int>*> pending_nodes;
    
  pending_nodes.push(root);
  
  while(pending_nodes.size() != 0)
  {
    BinaryTreeNode<int>* temp = pending_nodes.front();
    pending_nodes.pop();
    
    cout << temp -> data << ":";
    
    if(temp -> left != NULL)
      cout << "L:" << temp -> left -> data << ",";
    else
      cout << "L:" << "-1,";
    
    if(temp -> right != NULL)
      cout << "R:" << temp -> right -> data;
    else
      cout << "R:" << "-1";
    
    cout << endl;
 	
    if(temp -> left != NULL)
      pending_nodes.push(temp -> left);
    
    if(temp -> right != NULL)
      pending_nodes.push(temp -> right);
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
    printLevelWise(root);
}

*/