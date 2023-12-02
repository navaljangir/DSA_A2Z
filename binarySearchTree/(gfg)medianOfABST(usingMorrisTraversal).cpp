int morrisTraversal(Node* root){
    int count=0;
    Node* curr= root;
    while(curr!=NULL){
        if(curr->left==NULL){
            count++;
            curr=curr->right;
        }else{
            Node* pred = curr->left;
            while(pred->right!=curr && pred->right!=NULL){
                pred = pred->right;
            }
            if(pred->right==NULL){
                pred->right=curr;
                curr=curr->left;
            }else{
                count++;
                pred->right=NULL;
                curr=curr->right;
            }
        }
    
    }
    return count;
}
void getVal(Node* root , int&firstTerm, int&secondTerm ,int i){
    Node* curr =root;
    int count=0;
    while(curr!=NULL){
              if(curr->left==NULL){
                  count+=1;
                  if(count==i+1){
                    secondTerm = curr->data;
                  }
                  if(count==i){
                      firstTerm = curr->data;
                  }
                  curr=curr->right;
              }else{
                  Node* pred = curr->left;
                  while(pred->right!=NULL && pred->right!=curr){
                      pred = pred->right;
                  }
                  if(pred->right==NULL ){
                      pred->right=curr;
                      curr=curr->left;
                  }else{
                      count+=1;
                      pred->right=NULL;
                      if(count==i){
                          firstTerm =curr->data;
                      }
                      if(count==i+1){
                          secondTerm =curr->data;
                      }
                      curr= curr->right;
                  }
              }
              
          }
          
}

float findMedian(struct Node *root)
{
      //Code here
      int totalSize = morrisTraversal(root);
      if(totalSize%2==0){
          int num = (totalSize/2);
          int secondTerm = -1;
          int firstTerm = -1;
          getVal(root , firstTerm , secondTerm , num);
          return float(firstTerm + secondTerm)/2;
      }else{
          int num = (totalSize+1)/2;
          int firstTerm = -1;
          int secondTerm = -1;
          getVal(root , firstTerm , secondTerm ,num);
          return (float)firstTerm;
      }
}
