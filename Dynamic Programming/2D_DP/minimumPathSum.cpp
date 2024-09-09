//Memoization 
class Solution {
public:
    int solve(vector<vector<int>>&grid , int i ,int j , int n ,int m , vector<vector<int>>&dp){
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(i>=n || j>=m){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans1 = grid[i][j] + solve(grid , i+1 , j , n , m , dp);
        int ans2 = grid[i][j] + solve(grid ,i , j+1, n , m, dp );
        return dp[i][j] = min(ans1 , ans2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(grid, 0 ,0 ,n , m , dp);
    }
};

//Tabulation 
class Solution {
public:
    int solveTab(vector<vector<int>>&grid , int n , int m ){
        vector<vector<int>> dp(n+1 , vector<int>(m +1, 1e9));
        dp[n-1][m-1]= grid[n-1][m-1];
        for(int i= n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(!(i==n-1 && j==m-1)){
                dp[i][j] = grid[i][j] + min(dp[i+1][j] , dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return solveTab(grid , n , m);
    }
};

//space optimization 
class Solution {
public:
    int solveTab(vector<vector<int>>&grid , int n , int m ){
        vector<int> next(m , 1e9);
        next[m-1]= grid[n-1][m-1];
        for(int i= n-1;i>=0;i--){
            int nextVal = 1e9 ;
            for(int j = m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    nextVal = grid[i][j];
                }else{
                    next[j] = grid[i][j] + min(next[j] , nextVal);
                    nextVal = next[j];
                }
            }
            for(int i : next){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return next[0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return solveTab(grid , n , m);
    }
};
