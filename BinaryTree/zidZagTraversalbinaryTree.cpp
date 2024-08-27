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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        bool direction = 0; 
        q.push(root);
        vector<vector<int>> ans;
        vector<int> v;
        q.push(NULL);
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(top==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                if(direction){
                    reverse(v.begin() , v.end());
                }
                direction = !direction;
                ans.push_back(v);
                v.clear();
            }else{
                    v.push_back(top->val);
                    if(top->left){
                        q.push(top->left);
                    }
                    if(top->right){
                        q.push(top->right);
                    }
            }
        }
        return ans;
    }
};
