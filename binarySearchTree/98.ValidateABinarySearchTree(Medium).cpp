class Solution {
public:
    bool isValid(TreeNode* root , long long lb , long long ub){
       if(root==NULL){
           return true;
       }
       if(root->val>lb && root->val<ub){  
       bool leftAns = isValid(root->left , lb , root->val);
       bool rightAns = isValid(root->right , root->val , ub);
       return leftAns&&rightAns;
    }else{
        return false;
    }
    }
    bool isValidBST(TreeNode* root) {
        long long lb = LONG_MIN;
        long long up = LONG_MAX;
        return isValid(root , lb , up);
    }
};
