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


//Return when found O(1) Space 
class Solution {
public:
    int solve(TreeNode* root , int&k){
        if(root==NULL){
            return -1;
        }
        int ans =solve(root->left , k);
        if(ans!=-1){
            return ans;
        }
        k--;
        if(k==0){
            return root->val;
        }
        return solve(root->right , k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return solve(root , k );
    }
};
