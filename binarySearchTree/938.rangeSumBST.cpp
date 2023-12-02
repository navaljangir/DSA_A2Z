class Solution {
public:
    void solve(TreeNode*root, int low ,int high,int&ans){
        if(root==NULL){
            return;
        }
        if(root->val>=low && root->val<=high){
            ans+=root->val;
            solve(root->left , low ,high , ans);
            solve(root->right,low,high , ans);
        }
        if(root->val>high){
            solve(root->left , low , high , ans);
        }else if(root->val<low){
            solve(root->right, low , high , ans);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans =0 ;
        solve(root, low , high , ans);
        return ans;
    }
};
