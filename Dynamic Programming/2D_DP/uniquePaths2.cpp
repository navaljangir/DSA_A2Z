//Memoisation 
class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid , int i , int j , int n , int m , vector<vector<int>>&dp){
        if(i==n || j==m){
            return 0;
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans1 = solve(obstacleGrid ,i+1 , j , n ,  m , dp);
        int ans2 = solve(obstacleGrid , i , j+1 ,n ,m ,dp );
        return  dp[i][j] = ans1 + ans2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(obstacleGrid , 0 ,0,n , m ,dp);
    }
};


// Tabulation 
class Solution {
public:
    int solveTab(vector<vector<int>>& obstacleGrid){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<long long>> dp(n+1 , vector<long long>(m+1 , 0));
        dp[n-1][m-1] = 1; 
        for(int i = n -1; i >=0; i--){
            for(int j = m-1; j>=0; j--){
                if(!(i==n-1 && j==m-1) && obstacleGrid[i][j]==0){
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1){
            return 0;
        }
        return solveTab(obstacleGrid);
    }
};
