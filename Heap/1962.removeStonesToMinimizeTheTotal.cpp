class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        //max heap
        priority_queue<int> pq;
        for(int i =0 ; i <piles.size();i++){
            pq.push(piles[i]);
        }
        while(k>0){
            int qtop = pq.top();
            pq.pop();
            int numToPush = qtop - qtop/2;
            pq.push(numToPush);
            k--;
        }
        int sum =0 ;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};
