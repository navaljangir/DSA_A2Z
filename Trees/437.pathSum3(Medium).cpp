class Solution {
public: 
    long long ans = 0;
    void solve(TreeNode* root ,long long targetSum){
        if(root==NULL){
            return;
        }
        if(targetSum==root->val){
            ans++;
        }
        solve(root->left ,targetSum-root->val);
        solve(root->right , targetSum-root->val); 
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root!=NULL){
            solve(root , targetSum);
            pathSum(root->left , targetSum);
            pathSum(root->right , targetSum);
        }
        return ans;
    }
};
