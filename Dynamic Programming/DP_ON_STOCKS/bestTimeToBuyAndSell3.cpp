//Question Link : 

//Memoization 
class Solution {
public:
    int solve(int i , int cap ,int buy , vector<int> &prices , vector<vector<vector<int>>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(cap>=3){
            return 0;
        }
        if(dp[i][cap][buy]!=-1){
            return dp[i][cap][buy];
        }
        int ans1 =0 ;
        if(buy==0){
            ans1 = -prices[i] + solve(i+1 , cap+1 , 1 , prices, dp);
        }
        if(buy==1){
            ans1 =prices[i] + solve(i+1 , cap , 0, prices, dp);
        }
        int ans2 = solve(i+1 , cap , buy , prices, dp);
        return dp[i][cap][buy]=  max(ans1 , ans2 );
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(3 , vector<int>(2, -1)));
        return solve(0 ,0 ,0 , prices ,dp);
    }
};

//Tabulation 
class Solution {
public:
    int solveTab(vector<int>&prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(prices.size() +1, vector<vector<int>>(4 ,  vector<int>(2, -1e9)));
        for(int i =0 ; i <=3;i++){
            for(int j =0 ; j<=1;j++){
                dp[n][i][j] = 0;
            }
        }
        for(int i =0 ;  i <=n;i++){
            for(int j = 0;j<=1;j++){
                dp[i][3][j] = 0;
            }
        }
        for(int i = n-1;i>=0;i--){
            for(int j = 2;j>=0;j--){
                for(int k = 1;k>=0;k--){
                    int ans1 = 0;
                    if(k==0){
                        ans1 = -prices[i] + dp[i+1][j+1][1];
                    }
                    if(k==1){
                        ans1 = prices[i] + dp[i+1][j][0];
                    }
                    int ans2 = dp[i+1][j][k];
                    dp[i][j][k] = max(ans1,  ans2);
                }
            }
        }
        return dp[0][0][0];
    }
    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
    }
};
