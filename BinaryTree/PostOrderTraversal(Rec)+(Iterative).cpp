//Recursion 
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
    void postOrder(TreeNode* root , vector<int> &arr){
        if(root==NULL){
            return;
        }
        postOrder(root->left,arr);
        postOrder(root->right , arr);
        arr.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        postOrder(root,arr);
        return arr;
    }
};


//Iterative using 2 stacks

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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        stack<TreeNode*> st;
        stack<int> st2;
        st.push(root);
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            st2.push(top->val);
            if(top->left!=NULL){
                st.push(top->left);
            }
            if(top->right){
                st.push(top->right);
            }
        }   
        vector<int> ans;
        while(!st2.empty()){
            int top =st2.top();
            st2.pop();
            ans.push_back(top);
        }
        return ans;
    }
};
