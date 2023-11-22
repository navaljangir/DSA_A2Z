class Solution {
public:
    TreeNode* ans = NULL;
    void solve(TreeNode* root , int val){
        if(root==NULL){
            return;
        }
        if(root->val==val){
            ans = root;
            return;
        }
        solve(root->left , val);
        solve(root->right , val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        solve(root , val);
        return ans;
    }
};
