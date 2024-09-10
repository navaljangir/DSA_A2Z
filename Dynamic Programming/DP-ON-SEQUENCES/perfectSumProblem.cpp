//Memoization 
class Solution{

	public:
	int mod= 1e9+7;
	int solve(int arr[] , int n ,int sum ,int i , vector<vector<int>>&dp){
	    if(sum<0)
	    {
	        return 0;
	    }
	    if(i>=n){
	       if(sum==0){
	            return 1;
	        }
	        return 0;
	    }
	    if(dp[i][sum]!=-1){
	        return dp[i][sum];
	    }
	    int ans1 = solve(arr , n , sum-arr[i] , i+1 , dp) %mod;
	    int ans2 = solve(arr , n , sum  , i+1 ,dp) % mod;
	    return dp[i][sum] = (ans1 + ans2)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n , vector<int>(sum+1, -1));
        return solve(arr, n , sum , 0 , dp);
	}
	  
};
