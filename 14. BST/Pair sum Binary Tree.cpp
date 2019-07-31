#include<bits/stdc++.h>
using namespace std;

void traversal(BinaryTreeNode<int> *root, vector<int> &input)
{
    if(root == NULL)
        return;
    
    input.push_back(root -> data);
    traversal(root -> left, input);
    traversal(root -> right, input);
}

void nodesSumToS(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    vector<int> input;
    traversal(root, input);
    
    sort(input.begin(), input.end());

    int start = 0, end = input.size() - 1;

    while(start < end)
    {
        if(input[start] + input[end] == x)
        {
            if(input[start] == input[end])
            {
                int n = end - start + 1;
                int count = (n*(n-1)) / 2;

                while(count > 0)
                {
                    cout << input[start] << " " << input[end] << endl;
                    count--;
                }
                start = end;
            }
            else
            {
                int i = start, leftcount = 0;

                while(input[i] == input[start] && i < end)
                {
                    i++;
                    leftcount++;
                }

                int j = end, rightcount = 0;

                while(input[j] == input[end] && i > start)
                {
                    j--;
                    rightcount++;
                }

                start = i;
                end = j;

                int count = leftcount * rightcount;

                while(count > 0)
                {
                    cout << input[start - 1] << " " << input[end + 1] << endl;
                    count--;
                }
            }
        }
        else if(input[start] + input[end] < x)
            start++;
        else
            end--;
    }

}

/*
// Main Code

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
        if(left) {
            delete left;
        }
    if(right) {
            delete right;
        }
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
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}

*/