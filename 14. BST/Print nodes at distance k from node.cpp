void printans(BinaryTreeNode<int>* root, int k)
{
  if(root == NULL || k < 0)
    return;
  
  if(k == 0)
  {
    cout << root -> data << endl;
    return;
  }
  
  printans(root -> left, k - 1);
  printans(root -> right, k - 1);
}

int helper(BinaryTreeNode<int>* root, int node, int k)
{
  if(root == NULL)
    return -1;
  
  if(root -> data == node)
  {
    printans(root, k);
    return 0;
  }
  
  int leftans = helper(root -> left, node, k);
  
  if(leftans != -1)
  {
    if(leftans + 1 == k)
      cout << root -> data << endl;
    else 
      printans(root -> right, k - leftans - 2);
    
    return 1 + leftans;
  }
  
  int rightans = helper(root -> right, node, k);
  
  if(rightans != -1)
  {
    if(rightans + 1 == k)
      cout << root -> data << endl;
    else
      printans(root -> left, k - rightans - 2);
    
    return 1 + rightans;
  }
  
  return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
  
  helper(root, node, k);

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

    ~BinaryTreeNode() {
      if(left) 
          delete left;
      if(right) 
          delete right;
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
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}

*/