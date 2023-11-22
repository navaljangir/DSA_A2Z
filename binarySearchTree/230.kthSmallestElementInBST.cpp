class Solution {
public:
    vector<int> v;
    void solve(TreeNode* root ){
        if(root==NULL){
            return;
        }
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return -1;
        }
        solve(root);
        if(k>v.size()){
            return -1;
        }
        int ans = v[k-1];
        return ans;
    }
};
