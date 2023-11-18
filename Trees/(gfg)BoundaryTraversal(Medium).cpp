class Solution {
public:
vector<int> v;
    void printLeftBoundary(Node* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        v.push_back(root->data);
        if(root->left){
            printLeftBoundary(root->left);
        }else{
            printRightBoundary(root->right);
        }
    }
    void printLeafNode(Node* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->data);
            return;
        }
        printLeafNode(root->left);
        printLeafNode(root->right);
    }
    void printRightBoundary(Node*root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        if(root->right){
            printRightBoundary(root->right);
        }else{
            printRightBoundary(root->left);
        }
        v.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        v.push_back(root->data);
        printLeftBoundary(root->left);
        printLeafNode(root);
        printRightBoundary(root->right);
        return v;
        
    }
};
