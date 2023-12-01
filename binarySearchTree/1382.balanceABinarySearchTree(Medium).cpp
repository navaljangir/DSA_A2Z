class Solution {
public:
vector<int> inorder;
    void inorderTraverse(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorderTraverse(root->left);
        inorder.push_back(root->val);
        inorderTraverse(root->right);
    }
    TreeNode* buildTree(int s , int e){
        if(s>e){
            return NULL;
        }
        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = buildTree(s, mid-1);
        root->right= buildTree(mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return buildTree(0,inorder.size()-1);
    }
};
