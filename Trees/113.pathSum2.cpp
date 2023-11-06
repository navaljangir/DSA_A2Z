class Solution {
public:
void solve(TreeNode* root , int&targetSum , vector<int> v , vector<vector<int>>&ans , int sum){
        if(root==NULL){
            return;
        }
         if(sum+root->val==targetSum && (root->left==NULL && root->right==NULL)){
            v.push_back(root->val);
            ans.push_back(v);
            return;
        }
        v.push_back(root->val);
        solve(root->left , targetSum , v, ans , sum+root->val);
        solve(root->right , targetSum , v ,ans , sum+root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v; 
        solve(root , targetSum , v, ans , 0);
        return ans;
    }
};
