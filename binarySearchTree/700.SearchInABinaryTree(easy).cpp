//O(logn)
class Solution {
public:
    // TreeNode* ans = NULL;
    TreeNode* solve(TreeNode* root , int val){
        if(root==NULL){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        if(val<root->val){
            return solve(root->left , val);
        }else{
            return solve(root->right , val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root , val);
    }
};
//O(n)
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
