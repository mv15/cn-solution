/*
// Solution 1

#include<bits/stdc++.h>
using namespace std;

bool helper(BinaryTreeNode<int> *node, int min, int max) 
{ 
  if(node == NULL) 
     return true;
       
  if(node -> data < min || node -> data > max) 
     return false; 
 
  return helper(node -> left, min, node -> data) && helper(node -> right, node -> data, max);
} 

int height(BinaryTreeNode<int> *root) {
  if(root == NULL)
    return 0;
  
  int l = height(root -> left);
  int r = height(root -> right);
  
  return max(l,r) + 1;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
  
 if(helper(root, INT_MIN, INT_MAX))
 {
   return height(root);
 }
  
 int leftans = largestBSTSubtree(root -> left); 
 int rightans = largestBSTSubtree(root -> right);
  
 return max(leftans, rightans);
}

*/

#include<bits/stdc++.h>
using namespace std;

class bst
{
    public:
    int min;
    int max;
    int height;
    bool isbst;
};

bst helper(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        bst b;
        b.isbst = true;
        b.min = INT_MAX;
        b.max = INT_MIN;
        b.height = 0;
        return b;
    }

    bst leftans = helper(root -> left);
    bst rightans = helper(root -> right);

    if(leftans.isbst == false || rightans.isbst == false || root -> data < leftans.max || root -> data > rightans.min)
    {
        if(leftans.height > rightans.height)
        {
            leftans.isbst = false;
            return leftans;
        }

        rightans.isbst = false;
        return rightans;
    }

    bst ans;
    ans.isbst = true;
    ans.min = min(leftans.min, min(rightans.min, root -> data));
    ans.max = max(leftans.max, max(rightans.max, root -> data));
    ans.height = max(leftans.height, rightans.height) + 1;
    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    return helper(root).height;
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
    cout << largestBSTSubtree(root);
    delete root;
}

*/