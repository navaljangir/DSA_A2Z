//Recursion- TLE(time limit exceed)
class Solution {
public:
int mod = 1e9+7;
    int solve(int n , int&k ,int target){
        if(n<0){
            return 0;
        }
        if(n==0 && target==0){
            return 1;
        }
        if(n!=0 && target==0 || n==0 && target!=0){
            return 0;
        }
        int ans =0 ; 
        for(int i =1 ; i<=k;i++){
            if(target>=i){
                ans = (ans+solve(n-1 , k , target-i ))%mod;
            }
        }
        return  ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        return solve(n , k , target);
    }
};

//DP 
class Solution {
public:
int mod = 1e9+7;
    int solve(int n , int&k ,int target, vector<vector<int>>&dp){
        if(n<0){
            return 0;
        }
        if(n==0 && target==0){
            return 1;
        }
        if(n!=0 && target==0 || n==0 && target!=0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int ans =0 ; 
        for(int i =1 ; i<=k;i++){
            if(target>=i){
                ans = (ans+solve(n-1 , k , target-i ,dp))%mod;
            }
        }
        return dp[n][target] = ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1 ,-1));
        return solve(n , k , target , dp);
    }
};


//Tabulation
class Solution {
public:
int mod = 1e9+7;
    int totalRolls(int n , int k , int target){
        vector<vector<int>> dp(n+1, vector<int>(target+1 ,0));
        dp[0][0] = 1;
        for(int i =1;i<=n;i++){
            for(int t= 1; t<=target;t++){
                int ans = 0 ;
            for(int j = 1;  j<=k;j++){
                if(t>=j)
                ans = (ans + dp[i-1][t-j])%mod;
            }
            dp[i][t]= ans;
            }
        }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        return totalRolls(n , k , target);
    }
};

//Space optimised
class Solution {
public:
int mod = 1e9+7;
    int totalRolls(int n , int k , int target){
        vector<int> prev(target+1);
        vector<int> curr(target+1);
        prev[0] = 1;
        for(int i =1;i<=n;i++){
            for(int t= 1; t<=target;t++){
                int ans = 0 ;
            for(int j = 1;  j<=k;j++){
                if(t>=j)
                ans = (ans + prev[t-j])%mod;
            }
            curr[t]= ans;
            }
            prev = curr;
        }
        return prev[target];
    }
    int numRollsToTarget(int n, int k, int target) {
        return totalRolls(n , k , target);
    }
};
