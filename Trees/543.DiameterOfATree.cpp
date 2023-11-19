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
        int left= height(root->left);
        int right= height(root->right);
        return max(left , right)+1;
    }
    int diameter(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = diameter(root->left);
        int right = diameter(root->right);
        int maxDia =height(root->left) + height(root->right);
        return max(left, max(right , maxDia));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root);
    }
};


//Optimised to O(n)
class Solution {
public:
    int dia =  0;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left= height(root->left);
        int right= height(root->right);
        int currDia = left+right;
        dia = max(dia, currDia);
        return max(left , right)+1;
    }
    int diameterOfBinaryTree( TreeNode* root) {
        height(root);
        return dia;
    }
};
