
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        
        while(root != nullptr || !stack.empty()){
            if(root != nullptr){
                stack.push(root);
                root = root->left;
            }else{
                root = stack.top();
                result.push_back(root->val);
                stack.pop();
                root = root->right;
            }
        }
        return result;
    }
};
