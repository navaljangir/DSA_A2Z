//Question Link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1

//Memoization 
class Solution{
  public:
    int solve(int remaining, int &n ,  int price[] , vector<int>&dp){
        if(remaining<0){
            return -1e9;
        }
        if(remaining==0){
            return 0;
        }
        if(dp[remaining]!=-1){
            return dp[remaining];
        }
        int ans =0 ;
        for(int i =0; i< n ;i++){
            if(remaining>=i){
                ans = max(ans , price[i] + solve(remaining-i-1 , n , price , dp));
            }else{
                break;
            }
        }
        return dp[remaining] = ans;
    }
    int cutRod(int price[], int n) {
        vector<int> dp(n+1 , -1);
        return solve(n, n , price , dp);
    }
};

//Tabulation 
class Solution{
  public:
    int solveTab(int price[] ,int n){
        vector<int> dp(n+1 , -1e9);
        dp[0] = 0;
        for(int i= 1; i<=n;i++){
            int ans =0 ;
            for(int j = 0; j < n;j++){
                if(i>=j){
                    ans = max(ans , price[j] + dp[i-j-1]);
                }
                dp[i]=  ans;
            }
        }
        return dp[n];
    }
    int cutRod(int price[], int n) {
        return solveTab(price ,n);
    }
};
