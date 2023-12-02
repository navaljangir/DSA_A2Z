//Morris traversal
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        TreeNode* curr=root;
        int ans=0;
        while(curr!=NULL){
            if(curr->left==NULL){
                if(curr->val>=low && curr->val<=high)
                ans+=curr->val;
                curr=curr->right;
            }else{
                TreeNode* pred = curr->left;
                while(pred->right!=curr && pred->right!=NULL){
                    pred=pred->right;
                }
                if(pred->right==NULL){
                    pred->right=curr;
                    curr=curr->left;
                }else{
                     if(curr->val>=low && curr->val<=high)
                ans+=curr->val;
                    pred->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
//Recursion
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
