class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr =root;
        while(curr){
            if(curr->left){
                TreeNode* temp = curr->left;
                while(temp->right){
                    temp = temp->right;
                }
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left=NULL;
            }
            curr=curr->right; //Yha glti ho skti hai //curr=curr->left
        }
    }
};
