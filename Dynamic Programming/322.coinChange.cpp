//Recursion 
class Solution {
public:
    int solve(vector<int>&coins ,int amount ){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return 1e9;
        }
        int ans =1e9; 
        for(int i =0 ; i <coins.size();i++){
            ans = min(ans,1+ solve(coins, amount-coins[i]));
        }
        return ans;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins , amount);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};

//Top down 
class Solution {
public:
    int solve(vector<int>&coins ,int amount ,vector<int>&dp){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return 1e9;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int ans =1e9; 
        for(int i =0 ; i <coins.size();i++){
            ans = min(ans,1+ solve(coins, amount-coins[i] , dp));
        }
        return dp[amount] = ans;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = solve(coins , amount, dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};


// Bottom up 
