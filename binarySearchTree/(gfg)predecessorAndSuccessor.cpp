class Solution
{
    public:
    void solve(Node* root , Node*&pre , Node*&suc , int key){
        if(root==NULL){
            return;
        }
        if((suc->key==-1 && root->key>key )|| (root->key>key && suc->key>root->key)){
            suc = root;
        }
        if(pre->key==-1 && root->key<key || (pre->key<root->key && root->key<key)){
            pre=root;
        }
        solve(root->left , pre ,suc , key);
        solve(root->right , pre , suc , key);
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        suc = new Node(-1);
        pre=new Node(-1);
        solve(root , pre ,suc ,key);
        
    }
};
