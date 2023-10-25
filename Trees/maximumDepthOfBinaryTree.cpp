class Solution {
public:
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHeight = 1+solve(root->left);
        int rightHeight = 1+solve(root->right);
        return max(leftHeight , rightHeight);
    }
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};
