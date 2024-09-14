//Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

//Memoization 
class Solution {
public:
    int solve(vector<int>&prices ,  int i , int buy ,int cap , int &k , vector<vector<vector<int>>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(cap>k){
            return 0;
        }
        if(dp[i][cap][buy]!=-1){
            return dp[i][cap][buy];
        }
        int ans1 =0 ;
        if(buy==0){
            ans1 = -prices[i] + solve(prices , i+1 , 1 , cap+1 ,k ,dp);
        }
        if(buy==1){
            ans1=  prices[i] + solve(prices ,i+1 , 0 ,cap , k ,dp);
        }
        int ans2 = solve(prices , i+1 , buy ,cap , k ,dp);
        return dp[i][cap][buy] = max(ans1 , ans2);
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() , vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(prices ,0 ,0, 0 , k ,dp);
    }
};

//Tabulation 
class Solution {
public:
    int solveTab(vector<int>&prices ,int k){
        int n = prices.size();
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(k+2, vector<int>(2, -1e9)));
        for(int i =0 ; i <=k+1;i++)2
            for(int j= 0;j<2;j++){
                dp[n][i][j] = 0;
            }
        }
        for(int i =0 ; i <=n;i++){
            for(int j =0;j<2;j++){
                dp[i][k+1][j] = 0;
            }
        }
        for(int i = n-1;i>=0;i--){
            for(int j  = k+1;j>=0;j--){
                for(int buy = 0;buy<=1;buy++){
                    int ans1= 0;
                    if(buy==0){
                        ans1= -prices[i] + dp[i+1][j+1][1];
                    }
                    if(buy==1){
                        ans1 = prices[i] + dp[i+1][j][0];
                    }
                    int ans2 = dp[i+1][j][buy];
                    dp[i][j][buy]= max(ans1 , ans2);
                }
            }
        }
        return dp[0][0][0];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveTab(prices, k);
    }
};
