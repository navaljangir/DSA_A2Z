//Question Link : https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

//Memoization 
class Solution{
public:
    int solve(int i , int N , int W , int val[] , int wt[] , vector<vector<int>>&dp){
        if(W<0){
            return -1e9;
        }
        if(i>=N){
            return 0;
        }
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        int ans2 = solve(i+1 , N , W , val ,wt ,dp);
        int ans1 =val[i] +  solve(i , N , W-wt[i], val , wt, dp);
        return dp[i][W]=  max(ans2 , ans1);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W+1 , -1));
        return solve(0 , N , W , val , wt , dp);
    }
};

//Tabulation 
class Solution{
public:
    int solveTab(int N , int W , int val[] , int wt[]){
        vector<vector<int>> dp(N +1, vector<int>(W+1 , -1e9));
        for(int i = 0 ; i <=W;i++){
            dp[N][i] = 0;
        }
        for(int i = N-1; i>=0;i--){
            for(int j = 0;j<=W;j++){
                dp[i][j] = dp[i+1][j];
                if(j-wt[i]>=0){
                    dp[i][j] = max(dp[i][j], val[i] + dp[i][j-wt[i]]);
                }
            }
        }
        int ans = INT_MIN;
        for(int i =0 ; i <=W;i++){
            ans= max(ans , dp[0][i]);
        }
        return ans;
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return solveTab(N , W , val , wt );
    }
};
