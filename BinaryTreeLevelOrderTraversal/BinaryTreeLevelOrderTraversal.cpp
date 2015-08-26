#include <iostream>
#include <vector>
#include <queue>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

TreeNode* createTree(int a[]. int n)
{
    if(n <= 0) return NULL;
    TreeNode **tree = new TreeNode*[n];
    
    for(int i=0; i < n; i++){
        if(a[i] == 0){
            tree[i] == NULL;
            continue;
        }
        tree[i] = new TreeNode(a[i]);
    }
    return tree[0];
}




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root == nullptr) return result;
        
        vector<int> level;
        queue<TreeNode*> treenodes;
        treenodes.push(root);
        
        while(!treenodes.empty()){
            int size = treenodes.size();
            while(size > 0){
                TreeNode* node = treenodes.front();
                level.push_back(node->val);
                if(node->left != nullptr) treenodes.push(node->left);
                if(node->right != nullptr) treenodes.push(node->right);
                treenodes.pop();
                size--;
            }
            result.push_back(level);
            level.clear();
        }
        
        return result;
    }
};
