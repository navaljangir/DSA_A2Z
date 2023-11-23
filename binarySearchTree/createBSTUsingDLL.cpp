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
void convertIntoSortedDLL(Node* root , Node*&head){
    if(root==NULL){
        return;
    }
    convertIntoSortedDLL(root->right, head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head = root;
    convertIntoSortedDLL(root->left , head);
}
  void btToDLL(Node* root , Node*&head){
        if(root==NULL){
            return ;
        }
        btToDLL(root->left, head);
        if(head!=NULL){
        root->left = head;
            head->right =root;
        }
        head = root;
        // cout<<head->data<<" ";
        btToDLL(root->right , head);
    }
Node* createBSTUsingDLL(Node* &head , int n){
    if(n<=0  || head==NULL){
        return NULL;
    }
    Node* leftSubTree = createBSTUsingDLL(head , n-n/2-1);
    Node* root = head;
    root->left = leftSubTree;
    head = head->right;   //Yha pr glti kroge 
    root->right = createBSTUsingDLL(head , n/2);
    return root;
}
int main(){
Node* head = NULL;
Node* root = NULL;
insertBST(root);
btToDLL(root, head);
Node* temp = head;

}
