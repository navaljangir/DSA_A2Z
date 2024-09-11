//Question Link : https://leetcode.com/problems/coin-change/
//Memoization 
class Solution {
public:
    int solve(vector<int>&coins , int index, int amount , vector<vector<int>>&dp){
        if(amount<0){
            return 1e9;
        }
        if(amount==0){
            return 0;
        }
        if(index>=coins.size()){
            return 1e9;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int ans = INT_MAX;
        ans = min(ans ,1 + solve( coins , index , amount-coins[index]  ,dp));
        ans = min(ans , solve(coins , index+1 , amount , dp));
        return dp[index][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount +1, -1));
        int ans = solve(coins ,0 , amount , dp);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};

//Tabulation
class Solution {
public:
    int solveTab(vector<int>&coins , int amount){
        int n = coins.size();
        vector<vector<int>> dp( n+1 , vector<int>(amount+1 , 1e9));
        for(int i =0 ; i <=n;i++){
            dp[i][0] = 0 ;
        }
        for(int i= n-1;i>=0;i--){
            for(int j = 0; j<=amount;j++){
                dp[i][j] = dp[i+1][j];
                if(j-coins[i]>=0){
                    dp[i][j] = min(dp[i][j] ,1+ dp[i][j-coins[i]]);
                }
            }
        }
        return dp[0][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount +1, -1));
        int ans = solveTab(coins ,amount );
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};
