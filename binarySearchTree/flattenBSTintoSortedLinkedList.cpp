#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* createBST(Node* root ,int val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }
    if(root->data>val){
        root->left = createBST(root->left ,val);
    }
    if(root->data<val){
        root->right= createBST(root->right ,val);
    }
    return root;
}
void insertBST(Node* &root){
    int val;
    cin>>val;
    while(val!=-1){
        root = createBST(root , val);
        cin>>val;
    }
}
void inorder(Node*root  , Node* &prev){
    if(root==NULL){
        return;
    }
    inorder(root->left , prev);
    root->left=NULL;
    prev->right=root;
    prev= root;
    inorder(root->right , prev);
}
Node* flatten(Node*&root){
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    inorder(root , prev);
    root=dummy->right;
    return root;
}
// void inorder(Node*root  , Node* &prev){
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left , prev);
//     prev->left=NULL;
//     prev->right=root;
//     prev= root;
//     inorder(root->right , prev);
// }
// Node* flatten(Node*&root){
//     Node* dummy = new Node(-1);
//     Node* prev = dummy;
//     inorder(root , prev);
//     prev->left=NULL;
//     prev->right=NULL;
//     root=dummy->right;
//     return root;
// }
void print(Node* root){
    Node* curr=root;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}
int main(){
    Node* root= NULL;
    insertBST(root);
    root= flatten(root);
    cout<<endl;
    print(root);
}
