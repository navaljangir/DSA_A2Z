class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>> > , greater<pair<int,pair<int,int>>>> pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        vector<int> v(2);
        for(int i =0 ; i <nums.size();i++){
            mini = min(nums[i][0] , mini);
            maxi = max(nums[i][0] , maxi);
            pq.push({nums[i][0], {i,0} });
        }
        v[0]= mini;
        v[1]=maxi;
        int range = maxi - mini;
        while(!pq.empty()){
            auto ppi= pq.top(); //ppi -> pair of pair of int
            pq.pop();
            if(!pq.empty()){
                mini = pq.top().first;
            }
            int num = ppi.first;
            int r = ppi.second.first;
            int c = ppi.second.second;
            if(c+1 < nums[r].size()){
                pq.push({nums[r][c+1],{r,c+1}});
                mini = min(mini , nums[r][c+1]);
                maxi = max(maxi  , nums[r][c+1]);
                if(v[1]-v[0] > maxi - mini ){
                    v[0] = mini;
                    v[1] = maxi;
                }else if(v[1]-v[0]==maxi - mini){
                    v[0] = min(mini , v[0]);
                }
            }else{
                break;
            }
        }
        return v;
    }
};
