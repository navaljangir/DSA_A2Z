//Memoization 
class Solution {
public:
    int solve(int i , int j , int m , int n , vector<vector<int>>&dp){
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(i==n){
            return 0;
        }
        if(j==m){
            return 0; 
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans1 = solve(i+1 , j , m , n, dp);
        int ans2 = solve(i , j+1 ,m , n, dp);
        return dp[i][j]= ans1 + ans2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(0 ,0, n , m ,dp);
    }
};


//Tabulation
class Solution {
public:
    int solveTab(int m ,int n){
        vector<vector<int>> dp(n +1, vector<int>(m +1, 0));
        dp[n-1][m-1]= 1;
        for(int i = n-1; i>=0;i--){
            for(int j = m-1; j>=0;j--){
                if(!(i==n-1 && j==m-1)){
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        return solveTab(n , m);
    }
};

//Space optimized
class Solution {
public:
    int spaceOpti(int m ,int n){
        vector<int> next(m+1, 0);
        next[m-1] = 1;
        for(int i = n-1; i>=0;i--){
           int nextVal = 0;
            for(int j = m-1; j>=0;j--){
                if(i==n-1 && j == m-1){
                    nextVal = 1;
                }else{
                    next[j] = next[j] + nextVal;
                    nextVal = next[j];
                }
            }
    
        }
        return next[0];
    }
    int uniquePaths(int m, int n) {
        return spaceOpti(n , m);
    }
};
