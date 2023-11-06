

bool kthAncestor_helper(Node* root , int&k , int node , int &ans){
     if(root==NULL){
        return false;
    }
    if(root->data==node){
        return true; 
    }
    bool leftAns = kthAncestor_helper(root->left , k , node,ans);
    bool rightAns = kthAncestor_helper(root->right , k ,node,ans);
    if(leftAns || rightAns){
        k--;
       
    }
    if(k==0){
        ans = root->data;
        k=-1;
    }
    // return leftAns || rightAns;
    return leftAns || rightAns;
    
}
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    bool check  = kthAncestor_helper(root, k, node , ans);
    return ans; 
 
}


//Method 2


void solve(Node* root , int&k , int node , bool&found , int&ans){
    if(root==NULL){
        return;
    }
    if(root->data==node){
        found=true;
        return;
    }
    if(found==false){
    solve(root->left ,k , node , found,ans);
    }
    if(found==false)
    solve(root->right , k , node ,found,ans);
    if(found==true){
        --k;
    }
    if(k==0){
        ans= root->data;
    }
    return;

}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    bool found = false;
    int n = k;
    int ans = -1;
    solve(root,n , node , found , ans);
    return ans;
    
}
