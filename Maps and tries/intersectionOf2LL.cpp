class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        Node* temp2 = head2;
        unordered_map<int,int> mp;
        while(temp2!=NULL){
            mp[temp2->data]++;
            temp2 = temp2->next;
        }
        Node* temp1 = head1;
        Node* newNode = NULL;
        Node* curr = newNode;
        while(temp1!=NULL){
            if(mp.find(temp1->data)!=mp.end()){
                if(newNode ==NULL){
                    newNode= temp1;
                    curr= newNode;
                }else{
                    curr->next=temp1;
                    curr= temp1;
                }
            }
            temp1 = temp1->next;
        }
        curr->next=NULL;
        return newNode;
        
    }
};
