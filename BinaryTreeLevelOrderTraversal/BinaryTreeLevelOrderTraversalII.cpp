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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(result.begin(), result.end());
        return result;
    }
};
