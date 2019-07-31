void zigZagOrder(BinaryTreeNode<int> *root) 
{
  if(root == NULL)
     return;
  
  queue<BinaryTreeNode<int>*> pending;
  pending.push(root);
  
  bool flag = true;
  vector<int> v;
  
  while(pending.size() != 0)
  {
    int count = pending.size();
    
    flag = !flag;
    
    while(count > 0)
    {
    
       BinaryTreeNode<int>* temp = pending.front();
      
       v.push_back(temp -> data);
       pending.pop();
           
       if(temp -> left != NULL)
         pending.push(temp -> left);
       
       if(temp -> right != NULL)
         pending.push(temp -> right);
    
       count--;
    }
    
    if(flag == false)
    {
      for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
      cout << endl;
    }
    else
    {
      for(int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";
      cout << endl;
    }
    
    v.clear();
  }

}

/*
// Main code

#include <iostream>
#include <queue>
#include <stack>

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
    zigZagOrder(root);
}

*/