void solve(Node* root , int &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL){
        ans = root->data;
        return;
    }
    solve(root->left , ans);
}
int minValue(Node* root) {
    // Code here
    int ans= -1;
    solve(root ,ans);
    return ans;
    
}
