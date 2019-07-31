#include<bits/stdc++.h>
using namespace std;

template<typename T>
class maxnode
{
    public:
    TreeNode<T> *node;
    int sum;
};

maxnode<int>* helper(TreeNode<int> *root)
{
    if(root == NULL)
    {
        maxnode<int> *ans = new maxnode<int>();
        ans -> node = NULL;
        ans -> sum = INT_MIN;
        return ans;
    }
    
    int sum = root -> data;
    
    for(int i = 0; i < root -> children.size(); i++)
    {
        sum += root -> children[i] -> data;
    }
    
    maxnode<int> *ans = new maxnode<int>();
    ans -> node = root;
    ans -> sum = sum;
    
    for(int i = 0; i < root -> children.size(); i++)
    {
        maxnode<int>* child = helper(root -> children[i]);
        if(child -> sum > ans -> sum)
            ans = child;
    }
    
    return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root){
    return helper(root) -> node;
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
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}


*/