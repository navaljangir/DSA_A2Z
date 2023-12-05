class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(-1);
        ListNode* itr = ans;
        priority_queue<pair<int, pair<int,ListNode*>> , vector<pair<int, pair<int,ListNode*>>> , greater<pair<int, pair<int,ListNode*>>>> pq;
        for(int i= 0 ; i<lists.size(); i++){
            if(lists[i]!=NULL)
            pq.push({lists[i]->val , {i, lists[i]}});
        }
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int num = p.first;
            int r = p.second.first;
            ListNode* c = p.second.second;
            ListNode* newNode = new ListNode(num);
            itr->next = newNode;
            itr=newNode;
            if(c!=NULL && c->next!=NULL){
                pq.push({c->next->val, {r , c->next}});
            }
        }
        return ans->next;
    }
};
