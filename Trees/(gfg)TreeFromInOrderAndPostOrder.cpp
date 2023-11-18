int pos(int in[] , int n ,int start , int end ,  int element){
    for(int i = start ; i<=end ;i++){
        if(in[i]==element){
            return i;
        }
    }
    return -1;
}
Node* solve(int in[],  int post[] , int n , int inOrderStart , int inOrderEnd , int&postOrderIndex){
    if(postOrderIndex<0 || inOrderStart>inOrderEnd){
        return NULL;
    }
    int rootNodeData = post[postOrderIndex--];
    Node* root = new Node(rootNodeData);
    int posi = pos(in , n ,inOrderStart , inOrderEnd,  rootNodeData);
    root->right = solve(in , post, n , posi +1 , inOrderEnd , postOrderIndex);
    root->left = solve(in , post , n , inOrderStart , posi-1 , postOrderIndex);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int idx = n-1;
    return solve(in , post, n , 0 , n-1 ,idx);
}
