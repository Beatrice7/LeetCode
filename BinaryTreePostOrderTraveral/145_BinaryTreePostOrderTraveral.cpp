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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        TreeNode *p, *q;
        p = root;
        
        do{
            while(p){
                stack.push(p);
                p = p->left;
            }
            q = nullptr;
            while(!stack.empty()){
                p = stack.top();
                stack.pop();
                if(p->right == q){
                    result.push_back(p->val);
                    q = p;
                }else{
                    stack.push(p);
                    p = p->right;
                    break;
                }    
            }
        }while(!stack.empty());
        
        return result;
    }
};
