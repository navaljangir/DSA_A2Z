class Solution {
public:
    bool solve(TreeNode* p , TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        if((p!=NULL && q==NULL) || (q!=NULL && p==NULL)){
            return false;
        }
        if(p->val !=q->val){
            return false;
        }
        return solve(p->left , q->right) && solve(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};
