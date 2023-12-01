//T.C - O(logn)
//S.C - O(1)
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* succ = NULL;
        Node* curr = root;
        while(curr!=NULL){
            if(curr->data > x->data){
                succ= curr; // glti : curr ko root likh doge
                curr = curr->left;
            }else{
                curr=curr->right;
            }
        }
        
        return succ;
    }
};
