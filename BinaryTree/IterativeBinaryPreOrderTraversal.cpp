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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* start = root; 
        vector<int> ans;
        while(start!=NULL){
            if(start->left==NULL){
                ans.push_back(start->val);
                start = start->right;
            }else{
                TreeNode* traverseRight = start->left;
                TreeNode* leftNode = start->left;
                while(traverseRight->right!=NULL && traverseRight->right!=start){
                    traverseRight = traverseRight->right;
                }
                if(traverseRight->right==NULL){
                    ans.push_back(start->val);
                    traverseRight->right = start;
                    start = start->left;
                }else{
                    traverseRight->right= NULL;
                    start= start->right;
                }
            }

        }
        return ans;
    }
};
