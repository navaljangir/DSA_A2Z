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



//Iterative using 1 stacks

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        stack<TreeNode*> st;
        TreeNode* curr =root;
        vector<int> ans;
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode* temp = st.top()->right;
                if(temp==NULL){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && st.top()->right==temp){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }else{
                    curr = temp;
                }
            }
        }
        return ans;
    }
};
