/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftAns = height(root->left);
        int rightAns = height(root->right);
        return max(leftAns , rightAns)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        bool rootAns=false;
        if(abs(leftHeight-rightHeight)<=1){
            rootAns=true;
        }
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        return rootAns&&leftAns&&rightAns;
    }
};

//Optimised O(n)
class Solution {
public:
    bool isbalanced = true;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh)>1){
            isbalanced =false;
        }
        return max(lh , rh )+1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return isbalanced;
    }
};
