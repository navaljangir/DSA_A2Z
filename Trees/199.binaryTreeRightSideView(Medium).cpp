class Solution {
public:
    void solve(TreeNode* root , int i , vector<int>&v){
        if(root==NULL){
            return;
        }
        if(v.size()==i){
            v.push_back(root->val);
        }
        solve(root->right , i+1 , v);
        solve(root->left ,i +1 , v);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root , 0 , ans);
        return ans;
    }
};
