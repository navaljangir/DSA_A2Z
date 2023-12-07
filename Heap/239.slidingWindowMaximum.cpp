class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<pair<int,int>> q;
        priority_queue<pair<int,int>> pq;
        vector<int> ans; 
        int i =0 ; 
        int endingIndex = 0 ;
        while(i<nums.size()){
            while(q.size()<k){
                pq.push({nums[i] , i});
                q.push({i , nums[i]});
                endingIndex =i;
                i++;
            }
            int startingIndex = q.front().first;
            if(!q.empty())
            q.pop();
            while(!pq.empty() && (pq.top().second<startingIndex || pq.top().second>endingIndex)){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
    return ans;
    }
};
