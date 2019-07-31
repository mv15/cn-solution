void printLevelWise(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
  	if(root == NULL)
      return;
  	
  	queue<TreeNode<int>*> pendingNodes;
  	pendingNodes.push(root);
  
  	while(pendingNodes.size() != 0)
    {
      TreeNode<int>* front = pendingNodes.front();
      cout<< pendingNodes.front()->data << ":";
      pendingNodes.pop();
      
      for(int i = 0; i< front->children.size(); i++)
      {
        if(i != front->children.size() - 1)
          cout<< front->children[i]->data<< ",";
        else
          cout<< front->children[i]->data;
        pendingNodes.push(front->children[i]);
      }
      cout<< endl;
    }
}

/*
// Main code

#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


#include <queue>
#include "solution.h"

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}

*/