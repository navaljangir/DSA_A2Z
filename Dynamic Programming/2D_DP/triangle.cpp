//Memoization 
class Solution {
public:
    int solve(vector<vector<int>>&triangle , int i ,int j ,int n , vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(j>=i+1){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans1 = triangle[i][j] + solve(triangle, i+1 , j , n,dp);
        int ans2 = triangle[i][j] + solve(triangle, i+1, j+1, n ,dp);
        return dp[i][j] =  min(ans1 , ans2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n  , vector<int>(m , -1));
        return solve(triangle , 0 ,0 , n ,dp);
    }
};

//Tabulation 
class Solution {
public:
    int solveTab(vector<vector<int>>&triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 1e9));
        for(int i= 0; i < n ; i ++){
            dp[n][i] =0 ;
        }
        for(int i = n-1 ; i>=0;i--){
            for(int j = i; j>=0;j--){
                dp[i][j] = triangle[i][j]+ min(dp[i+1][j] , dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solveTab(triangle);
    }
};

//space optimization 
class Solution {
public:
    int solveTab(vector<vector<int>>&triangle){
        int n = triangle.size();
        vector<int> next(n+1 ,0 );
        vector<int> curr(n+1 , 1e9);
        for(int i = n-1 ; i>=0;i--){
            int diagonalValue = 1e9;
            for(int j = i; j>=0;j--){
                curr[j]= triangle[i][j]+ min(next[j], next[j+1]);
            }
            next = curr;
        }
        return next[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solveTab(triangle);
    }
};
