//Question Link : 

//DP Memoization

class Solution {
public:
    int solve(vector<int>&prices, int i ,int buy, vector<vector<int>> & dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int ans1=0; 
        if(buy==0){
            ans1 = -prices[i] + solve(prices , i + 1 , 1 , dp);
        }
        if(buy==1){
            ans1 = prices[i]+ solve(prices , i+1 , 0 , dp);
        }
        int ans2 = solve(prices , i+1 , buy, dp);
        return dp[i][buy] = max(ans1 , ans2);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() , vector<int>(2 , -1));
        return solve(prices ,0 , 0,dp);
    }
};

// Greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0; 
        int buy = -1;
        for(int i=0 ; i < prices.size();i++){
            if(buy==-1){
                buy = prices[0];
            }
            if(buy<prices[i]){
                ans =ans+ prices[i]-buy;
                buy = prices[i];
            }
            if(buy>prices[i]){
                buy = prices[i];
            }
        }
        return ans;
    }
};
