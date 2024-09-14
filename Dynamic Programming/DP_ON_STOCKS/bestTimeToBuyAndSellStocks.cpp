//Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

//class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> v(prices.size());
        v[0]= prices[0];
        int mini = v[0];
        for(int i =1; i<prices.size();i++){
            mini = min(mini , prices[i]);
            v[i] = mini;
        }
        int ans =0 ;
        for(int i =0 ; i < prices.size();i++){
            ans = max(ans , prices[i] -v[i]);
        }
        return ans;
    }
};
