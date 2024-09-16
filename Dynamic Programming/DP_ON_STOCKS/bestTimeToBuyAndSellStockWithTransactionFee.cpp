// Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

// Memoization 

class Solution {
public:
    int solve(int index, int buy , vector<int>&prices , int &fee , vector<vector<int>>&dp){
        if(index>=prices.size()){
            return 0;
        }
        int ans1 = 0 ;
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        if(buy==0){
            ans1 = -prices[index] + solve(index+1 , 1 , prices ,fee , dp);
        }
        if(buy==1){
            ans1 = prices[index] -fee + solve(index+1 , 0 , prices , fee ,dp);
        }
        int ans2 = solve(index+1 , buy , prices, fee, dp);
        return dp[index][buy] =  max(ans1 , ans2);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size() , vector<int>(2, -1));
        return solve(0 , 0, prices,fee ,dp);
    }
};

//Tabulation 
class Solution {
public:
    int solveTab(vector<int>&prices , int &fee){
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2, -1e9));
        dp[n][0]= 0;
        for(int i =n-1;i>=0;i--){
            for(int j = 0;j<=1;j++){
                int ans1 = 0;
                if(j==0){
                    ans1 = -prices[i] + dp[i+1][1];
                }
                if(j==1){
                    ans1 = prices[i] - fee + dp[i+1][0];
                }
                int ans2 = dp[i+1][j];
                dp[i][j] = max(ans1 ,ans2);
            }
        }
        return dp[0][0];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solveTab(prices, fee);;
    }
};
