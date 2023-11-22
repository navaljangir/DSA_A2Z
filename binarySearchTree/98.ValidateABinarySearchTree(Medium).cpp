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


//Using inorder traversal Concept (As we know in inorder traversal of binart search tree(bst) values are in sorted order)
class Solution {
public:
    void isValid(TreeNode* root,vector<long long>& v){
       if(root==NULL){
           return;
       }
       isValid(root->left, v);
       v.push_back(root->val);
       isValid(root->right , v);
    }
    bool isValidBST(TreeNode* root) {
        vector<long long> v;
        isValid(root , v);
        for(int i =1 ;i<v.size();i++){
            if(v[i]<=v[i-1]){
                return false;
            }
        }
        return true;
    }
};
