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
    int ans= 0;
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftAns = solve(root->left);
        int rightAns =  solve(root->right);
        ans = max(ans, leftAns + rightAns);
        return max(1+ leftAns ,1+ rightAns);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
