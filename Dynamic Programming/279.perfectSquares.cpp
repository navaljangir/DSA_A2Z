class Solution {
public:
    int solve(int sum , int&n, vector<int>& dp){
        if(sum>n){
            return 1e9;
        }
        if(sum==n){
            return 0;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int ans = INT_MAX;
        for(int i = 1 ; i*i<=n;i++){
            ans = min(ans ,1+solve(sum+(i*i) , n , dp));
        }
        return dp[sum] = ans;
    }

    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        if(n==1){
            return 1;
        }
        return solve(0 , n , dp);
    }
};
