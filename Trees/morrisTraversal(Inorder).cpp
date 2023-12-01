class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred = pred->right;
                }
                if(pred->right!=NULL){
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }else{
                    pred->right= curr;
                    curr=curr->left;
                }
            }
        }
        return ans;
    }
};
