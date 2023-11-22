//time complexity : o(n)

class Solution {
public:
    vector<int> v;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        solve(root);
        int i = 0 ;
        int j = v.size()-1;
        while(i<j){
            if(v[i]+v[j]==k){
                return true;
            }
            if(v[i]+v[j]>k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};
