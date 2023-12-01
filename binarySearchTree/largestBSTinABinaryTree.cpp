#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data =data;
        this->left= NULL;
        this->right=NULL;
    }
};
class NodeData{
public:  //yha glti hogi u might not use public
    int minVal;
    int maxVal;
    int size ;
    bool validBST;
    NodeData(){

    }
    NodeData(int size ,int min , int max , bool valid){
        this->size = size;
        this->minVal=min;
        this->maxVal=max;
        this->validBST=valid;
    }
};
NodeData solve(Node* root , int &ans){
    if(root==NULL){
        NodeData temp(0 , INT_MAX , INT_MIN , true);
        return temp;
    }
    NodeData leftKaAns = solve(root->left , ans);
    NodeData rightKaAns = solve(root->right , ans);
    NodeData currNodeKaAns;
    currNodeKaAns.size = leftKaAns.size + rightKaAns.size+1;
    currNodeKaAns.maxVal = max(root->data , rightKaAns.maxVal);
    currNodeKaAns.minVal = min(root->data , leftKaAns.minVal);
    if(leftKaAns.validBST && rightKaAns.validBST && root->data > leftKaAns.maxVal && root->data < rightKaAns.minVal){
        currNodeKaAns.validBST=true;
    }else{
        currNodeKaAns.validBST=false;
    }
    if(currNodeKaAns.validBST){
        ans = max(ans , currNodeKaAns.size);
    }
    return currNodeKaAns;
}

int main(){
Node* root = new Node(5);
Node* first = new Node(2);
Node* second = new Node(4);
Node* third = new Node(1);
Node* fourth = new Node(3);
root->left = first ;
root->right = second;
first->left = third;
first->right = fourth;
int ans =0 ;
NodeData temp = solve(root, ans);
cout<<ans;
}
