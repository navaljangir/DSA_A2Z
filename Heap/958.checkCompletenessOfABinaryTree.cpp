class Solution {
public:
    int sizeOfTree(TreeNode*root){
        if(root==NULL){
            return 0 ;
        }
        return 1+sizeOfTree(root->left) + sizeOfTree(root->right);
    }
    bool isCBT(TreeNode* root ,long long i , int&size){
        if(root==NULL){
            return true;
        }
        if(i>size){
            return false;
        }
        bool leftKaAns = isCBT(root->left , 2*i , size);
        bool rightKaAns=isCBT(root->right , 2*i+1 , size);
        return leftKaAns && rightKaAns;
    }
    bool isCompleteTree(TreeNode* root) {
        int size = sizeOfTree(root);
       return isCBT(root, 1 , size);
    }
};
