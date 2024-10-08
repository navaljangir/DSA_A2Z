// Question Link : https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Memoization 

class Solution{
public:
    int solve(int arr[] , int n , int i , int j , vector<vector<int>>&dp){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 1e9;
        for(int k = i;k< j;k++){
            int val = arr[i-1] * arr[k] * arr[j] + solve(arr , n , i , k ,dp) + solve(arr , n , k+1 ,j , dp);
            ans = min(ans , val);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1 , vector<int>(N+1 , -1));
        return solve(arr ,N , 1 , N-1 ,dp);
    }
};

// Tabulation 
class Solution{
public:
    int solveTab(int arr[] , int N){
        vector<vector<long long>> dp(N+2, vector<long long>(N+2 , 1e9));
        for(int i = 0;i<=N;i++){
            dp[i][i] = 0; 
        }
        for(int i=N-1;i>=1;i--){
            for(int j = 1;j<=N-1;j++){
                long long ans = 1e9;
                for(int k = i; k<j;k++){
                    ans = min(ans , arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j]);
                }
                if(i!=j){
                    dp[i][j] = ans;
                }
            }
            
        }
        return dp[1][N-1];
    }
    int matrixMultiplication(int N, int arr[])
    {
        return solveTab(arr ,N); 
    }
};
