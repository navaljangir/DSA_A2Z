class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums[0].size(); 
        vector<int> ans;
        for(int i = 0; i <queries.size();i++){
            priority_queue<pair<string,int>,vector<pair<string,int>> , greater<pair<string,int>>> pq;
            int trim = queries[i][1];
            int kSmallest = queries[i][0];
            for(int j = 0 ; j<nums.size();j++){
                string s = nums[j];
                pq.push({s.substr(n-trim , trim),j});
            }
            while(!pq.empty() && kSmallest>1){
                pq.pop();
                kSmallest--;
            }
            int num = pq.top().second;
            ans.push_back(num);
        }
        return ans;
    }
};
