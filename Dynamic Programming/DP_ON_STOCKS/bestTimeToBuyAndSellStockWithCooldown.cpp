//Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

//Memoization 
class Solution {
public: 
    int solve(vector<int>&prices,int index,int buy , vector<vector<int>>&dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int ans1= 0 ;
        if(buy==0){
            ans1 = -prices[index] + solve(prices , index+1 , 1 , dp);
        }   
        if(buy==1){
            ans1= prices[index]+ solve(prices ,index+2 , 0 ,dp); 
        }
        int ans2 = solve(prices , index+1 ,buy ,dp);
        return dp[index][buy] = max(ans1 , ans2);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return solve(prices , 0 ,0 ,dp);
    }
};

//Tabulation 
class Solution {
public: 
    int solveTab(vector<int>&prices){
        int n = prices.size();
        vector<vector<int>> dp(n+2 , vector<int>(2, -1e9));
        dp[n][0]=0;
        dp[n][1]=0;
        dp[n+1][0] = 0;
        dp[n+1][1]= 0;
        for(int i = n-1;i>=0;i--){
            for(int j = 1;j>=0;j--){
                int ans1 = 0;
                if(j==0){
                    ans1 =-prices[i] + dp[i+1][1];
                }
                if(j==1){
                    ans1 = prices[i] + dp[i+2][0];
                }
                int ans2 = dp[i+1][j];
                dp[i][j] = max(ans1 , ans2);
            }
        }
        return dp[0][0];
    }
    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
    }
};

//
