//using inorder predecessor
class Solution {
public:
    int maxValue(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->right==NULL){
            return root->val;
        }
        return maxValue(root->right);
    }
    TreeNode* solve(TreeNode* root , int key){
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }else if(root->left!=NULL && root->right==NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else if(root->left==NULL && root->right!=NULL){
                TreeNode*temp = root->right;
                delete root;
                return temp;
            }else{
                int findMaxRoot= maxValue(root->left);
                root->val = findMaxRoot;
                root->left = solve(root->left , findMaxRoot);
            }
        }else if(root->val<key){
            root->right = solve(root->right , key);
        }else{
            root->left = solve(root->left , key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
     return solve(root , key);   
    }
};

//using inoder successor
class Solution {
public:
    int minValue(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL){
            return root->val;
        }
        return minValue(root->left);
    }
    TreeNode* solve(TreeNode* root , int key){
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }else if(root->left!=NULL && root->right==NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else if(root->left==NULL && root->right!=NULL){
                TreeNode*temp = root->right;
                delete root;
                return temp;
            }else{
                //inorder successor
                int inordersucc= minValue(root->right);
                root->val = inordersucc;
                root->right = solve(root->right , inordersucc);
            }
        }else if(root->val<key){
            root->right = solve(root->right , key);
        }else{
            root->left = solve(root->left , key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
     return solve(root , key);   
    }
};
