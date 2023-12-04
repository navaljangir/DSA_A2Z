//Checking the index of left and right tree at run time

class Solution {
  public:
    int sizeOfBT(Node* root ){
        if(root==NULL){
            return 0;
        }
        return 1+sizeOfBT(root->left) + sizeOfBT(root->right);
    }
    bool isCBT(Node* root, int i , int &size){
        if(root==NULL){
            return true;
        }
        if(i>size){
            return false;
        }
        bool leftAns = isCBT(root->left , 2*i , size);
        bool rightAns = isCBT(root->right , 2*i+1 , size);
        return leftAns && rightAns;
    }
    pair<bool , int> solve(Node* root) {
        if(root==NULL){
            return {true, 0};
        }
        if(root->left==NULL && root->right!=NULL){
            return {false ,root->data};
        }
        if(root->left==NULL && root->right==NULL){
            return {true,root->data};
        }
        pair<bool , int> leftAns = solve(root->left);
        pair<bool, int> rightAns = solve(root->right);
        if(leftAns.first==true && rightAns.first==true && root->data>leftAns.second && root->data>rightAns.second){
            return {true, root->data};
        }
        else{
            return {false, root->data};
        }
    }
    bool isHeap(struct Node* tree) {
       int size = sizeOfBT(tree);
        return isCBT(tree , 1 , size ) && solve(tree).first;
    }
};
//below isCBT function will give the runtime error if we run it on leetcode as it continues to calculate the index of left and right child so to optimise this check next solution
class Solution {
  public:
    void isCBT(Node* root , int&totalCount , int count, int &maxi){
        if(root==NULL){
            return;   
        }
        if(root->left==NULL && root->right==NULL){
            totalCount++;
            maxi = max(count,maxi);
            return;
        }
        int left = 2* count;
        int right= 2*count+1;
        totalCount++;
        isCBT(root->left , totalCount, left, maxi);
        isCBT(root->right , totalCount ,right, maxi);
    }
    pair<bool , int> solve(Node* root) {
        if(root==NULL){
            return {true, 0};
        }
        if(root->left==NULL && root->right!=NULL){
            return {false ,root->data};
        }
        if(root->left==NULL && root->right==NULL){
            return {true,root->data};
        }
        pair<bool , int> leftAns = solve(root->left);
        pair<bool, int> rightAns = solve(root->right);
        if(leftAns.first==true && rightAns.first==true && root->data>leftAns.second && root->data>rightAns.second){
            return {true, root->data};
        }
        else{
            return {false, root->data};
        }
    }
    bool isHeap(struct Node* tree) {
        // code here
        int totalCount= 0 ;
        int maxi =  0;
        isCBT(tree , totalCount , 1, maxi);
        if(maxi!=totalCount){
            return false;
        }
        return solve(tree).first;
    }
};


//
