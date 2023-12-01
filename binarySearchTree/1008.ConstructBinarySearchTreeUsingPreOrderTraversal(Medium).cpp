//Space - O(N)
//Time Complexity : O(N^2)
class Solution {
public:
    int findPosi(vector<int>& inorder , int element){
        for(int i =0 ; i<inorder.size();i++){
            if(element==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>&preorder ,int s,int &index ,  int e ,vector<int>&inorder){
        if(s>e || index>=preorder.size()){
            return NULL;
        }
        int pos= findPosi(inorder , preorder[index]);
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = solve(preorder , s ,index, pos-1 , inorder);
        root->right = solve(preorder  , pos+1, index ,e, inorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin() , inorder.end()); 
        int index =0;
        return solve(preorder, 0,index , preorder.size()-1 , inorder);
    }
};

//S.C - O(1) 
//T.C - O(nlogn)
class Solution {
public:
    TreeNode* buildTree(TreeNode* root , int num){
        if(root==NULL){
            TreeNode* newNode = new TreeNode(num);
            return newNode;
        }
        if(num>root->val){
          root->right =   buildTree(root->right , num);
        }else{
            root->left = buildTree(root->left , num);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(auto i : preorder){
            root= buildTree(root , i);
        }
        return root;
    }
};
