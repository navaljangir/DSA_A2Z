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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty()){
            if(q.front()!=NULL)
            v.push_back(q.front()->val);
            if(q.front()==NULL){
                ans.push_back(v);
                v.clear();
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
               continue;
            }
            if(q.front()->left){
                q.push(q.front()->left);
            }
            if(q.front()->right){
                q.push(q.front()->right);
            }
            q.pop();
        }
        return ans;
    }
};
