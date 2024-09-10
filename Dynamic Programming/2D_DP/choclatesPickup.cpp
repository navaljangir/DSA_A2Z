//Memoization 
class Solution {
  public:
    int helper(vector<vector<int>>&grid, int i ,int j ,int c , int &n ,int &m , vector<vector<vector<int>>>&dp){
        if(j<0 || j>=m || c<0 || c>=m){
            return -1e9;
        }
        if(i>=n){
            return 0;
        }
        if(dp[i][j][c]!=-1){
            return dp[i][j][c];
        }
        int ans = 0;
        if(j!=c){
            ans = grid[i][j] + grid[i][c]; 
        }else{
            ans = grid[i][j]; 
        }
        int ans1 = helper(grid ,i+1 , j-1, c-1, n , m, dp);
        ans1 = max(ans1 , helper(grid, i+1 , j -1,  c, n , m, dp));
        ans1 = max(ans1 , helper(grid , i+1, j-1 , c+1 ,n , m, dp));
        ans1 = max(ans1 , helper(grid , i +1 , j , c-1 , n , m ,dp));
        ans1 = max(ans1 , helper(grid , i +1 , j , c , n , m, dp));
        ans1 = max(ans1 , helper(grid , i+1 , j , c+1 , n , m, dp));
        ans1 = max(ans1 , helper(grid , i+1 , j+1 , c-1 , n , m, dp));
        ans1 = max(ans1 , helper(grid, i +1 , j+1 , c , n , m, dp));
        ans1 = max(ans1 , helper(grid ,i+1 , j+1 , c+1, n , m, dp));
        return dp[i][j][c]= ans + ans1;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(m , vector<int>(m , -1)));
        return helper(grid, 0 , 0, m-1 , n , m, dp);
    }
};
