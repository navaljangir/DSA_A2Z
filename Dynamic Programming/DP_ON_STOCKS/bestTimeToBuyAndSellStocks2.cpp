//Question Link : 

//DP approach :=> TLE

class Solution {
public:
    int solve(vector<int>&prices, int i , int prev , vector<vector<int>> & dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int ans1=0; 
        if(prev==-1){
            ans1 = solve(prices , i+1 , i , dp);
        }else if(prices[i] >= prices[prev]){
            ans1 = prices[i] - prices[prev] + solve(prices, i+1 , -1 ,dp);
        }
        int ans2 = solve(prices , i+1 , prev, dp);
        return dp[i][prev+1] = max(ans1 , ans2);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() , vector<int>(prices.size()+1, -1));
        return solve(prices ,0 , -1 ,dp);
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
