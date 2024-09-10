//Memoization 
class Solution {
public:
    int solve(vector<vector<int>>&matrix , int i ,int j , int &n ,  vector<vector<int>>&dp){
      if(j>=n || j<0){
            return 1e9;
        }
        if(i>=n){
            return 0;
        }
        if(dp[i][j]!=-1e9){
            return dp[i][j];
        }
        int ans1 = solve(matrix , i+1 , j-1, n, dp);
        int ans2 = solve(matrix, i+1 , j , n, dp);
        int ans3 = solve(matrix , i+1 , j+1 , n , dp);
        return dp[i][j] = matrix[i][j] + min({ans1 , ans2 , ans3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans= INT_MAX;
        vector<vector<int>> dp(n , vector<int>(n , -1e9));
        for(int i =0 ; i < n;i++){
            ans = min(ans , solve(matrix , 0 , i , n ,dp));
        }
        return ans;
    }
};

//Tabulation
class Solution {
public:
    int solveTab(vector<vector<int>>&matrix){
        int n = matrix.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 1e9));
        for(int i = 0 ; i <=n;i++){
            dp[n][i] = 0;
        }
        for(int i = n-1; i>=0;i--){
            for(int j = n-1;j>=0;j--){
                dp[i][j] =matrix[i][j] +  min({dp[i+1][j] , dp[i+1][j+1]});
                if(j-1>=0){
                    dp[i][j] = min(dp[i][j] ,matrix[i][j] + dp[i+1][j-1]);
                }
                
            }
        }
        int ans = INT_MAX;
        for(int i =0 ; i< n ; i ++){
            ans = min(ans , dp[0][i]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans= INT_MAX;
        return solveTab(matrix);
    }
};

//Space optimised
class Solution {
public:
    int spaceOpti(vector<vector<int>>&matrix){
        int n = matrix.size();
        vector<int> next(n+1 , 0);
        vector<int> curr(n+1, 1e9);
        for(int i = n-1; i>=0;i--){
            for(int j = n-1;j>=0;j--){
                curr[j] =matrix[i][j] +  min({next[j] ,next[j+1]});
                if(j-1>=0){
                    curr[j]= min(curr[j] , matrix[i][j] + next[j-1]);
                }
            }
            next =curr;
        }
        int ans = INT_MAX;
        for(int i =0 ; i< n ; i ++){
            ans = min(ans , next[i]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans= INT_MAX;
        return spaceOpti(matrix);
    }
};
