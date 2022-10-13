#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        //Your code here
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        map<int, int> topNode;   // <horizontal distance(hd), node->data>
        queue<pair<Node *, int>> q; // <node, hd>
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *frontNode = temp.first;
            int hd = temp.second;
            
            // Just remove this condition from top view. Rest is same
            // if(topNode.find(hd) == topNode.end())
            
            topNode[hd] = frontNode -> data;    // Overwrites data
                
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
                
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i : topNode){
            ans.push_back(i.second);
        }
        return ans;
    }
};