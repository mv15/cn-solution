
class BST {
	// Complete this class
  BinaryTreeNode<int>* root;
  
  public:
  BST()
  {
    root = NULL;
  }
  
  ~BST()
  {
    delete root;
  }
  
  private:
  
  bool has(int data, BinaryTreeNode<int>* node)  // helper function for search
  {
    if(node == NULL)
      return false;
    
    if(node -> data == data)
      return true;
    else if(node -> data > data)
      return has(data, node -> left);
    else 
      return has(data, node -> right);
  }
  
  public:
  
  bool hasData(int data)  // main function for search
  {
     return has(data, root);
  }
  
  private:
  
  BinaryTreeNode<int>* insertHelper(int data, BinaryTreeNode<int>* node) // helper for insert  // works fine
  {
    if(node == NULL) 
    {
      BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(data);
      return temp;
    }
    
    if(node -> data > data)
    {
      node -> left = insertHelper(data, node -> left);
    }
    else 
    {
      node -> right = insertHelper(data, node -> right);
    }
    return node;
  }
  
  public:
  
  void insert(int data)  // main for insert  // works fine
  {
      this -> root = insertHelper(data, root);
  }
  
  private:
   
  BinaryTreeNode<int>* minimum(BinaryTreeNode<int>* node)  // helper to find inorder successor (delete )
  {
    BinaryTreeNode<int>* temp = node;
    
    while(temp -> left != NULL)
    {
      temp = temp -> left;
    }
    
    return temp;
  }
  
  private:
  
  BinaryTreeNode<int>* deletehelper(int data, BinaryTreeNode<int>* node) // helper for delete
  {
    if(node == NULL)
      return node;
    
    if(node -> data > data)
    {
      node -> left = deletehelper(data, node -> left);
    }
    else if(node -> data < data)
    {
      node -> right = deletehelper(data, node -> right);
    }
    else
    {
      if(node -> left == NULL)
      {
        BinaryTreeNode<int>* temp = node -> right;
        delete node;
        return temp;
      }
      else if(node -> right == NULL)
      {
        BinaryTreeNode<int>* temp = node -> left;
        delete node;
        return temp;
      }
      
      BinaryTreeNode<int>* temp = minimum(node -> right);
      node -> data = temp -> data;
      
      node -> right = deletehelper(temp -> data, node -> right);
    }
  }
  
  public:
  
  void deleteData(int data) // main function of helper
  {
    BinaryTreeNode<int>* temp = deletehelper(data, root);
  }
  
  private:
  
  void printT(BinaryTreeNode<int>* node)  // works fine
  {
    if(node == NULL)
      return;
    
    cout << node -> data << ":" ;
    
    if(node -> left != NULL)
      cout << "L:" << node -> left -> data << "," ;
    
    if(node -> right != NULL)  
      cout << "R:" << node -> right -> data ;
    
    cout << endl;
    
    printT(node -> left);
    printT(node -> right);
  }
  
  public:
  
  void printTree()  // works fine
  {
    printT(root);
  }
    
};

/*
// Main code

#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

#include "BinarySearchTree.h"


int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}

*/