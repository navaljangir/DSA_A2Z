class Solution{
    public:
    int pos(int in[] , int n ,int i , int j,  int element){
        for(int  k  = i  ; k<=j ; k++){
            if(in[k]==element){
                return k;
            }
        }
        return -1;
    }
    Node* solve(int in[] , int pre[] , int&n , int inOrderStart ,int inOrderEnd, int&preOrderIndex){
        if(preOrderIndex>=n || inOrderStart>inOrderEnd){
            return NULL;
        }
        int rootNodeData = pre[preOrderIndex++];
        Node* root = new Node(rootNodeData);
        int posi = pos(in , n ,inOrderStart , inOrderEnd , rootNodeData);
        root->left = solve(in , pre , n , inOrderStart , posi-1 , preOrderIndex);
        root->right = solve(in , pre, n , posi+1 , inOrderEnd ,preOrderIndex);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex =0 ; 
        return solve(in , pre , n , 0 , n-1, preOrderIndex);
            
    }
};
