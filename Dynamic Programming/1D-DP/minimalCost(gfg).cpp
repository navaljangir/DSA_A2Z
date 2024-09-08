//Memoization

class Solution {
  public:
    int solve(int index , int &k , vector<int>&arr , int n , vector<int>&dp){
        if(index==n-1){
            return 0;  
        }
        if(index>=n){
            return 1e9;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans = 1e9;
        for(int i = index+1; i <= min(n-1 , index+ k);i++){
            ans = min(ans , abs(arr[index] - arr[i] ) + solve(i ,k , arr , n, dp ));
        }
        return dp[index] = ans;
    }
    int minimizeCost(vector<int>& arr, int& k) {
        vector<int> dp(arr.size()+1 , -1 );
        return solve(0 , k ,arr , arr.size() , dp);
    }
};

//Tabulation 
class Solution {
  public:
    int solveTab(vector<int>&arr , int k){
        vector<int> dp(arr.size()+1 , 1e9);
        int n= arr.size();
        dp[n-1] = 0 ;
        for(int i= n-2; i >=0 ;i--){
            for(int j = i+1; j <= min(n-1 , i+k); j++){
                dp[i] = min(dp[i] , abs(arr[i] - arr[j]) + dp[j]);
            }
        }
        return dp[0];
    }
    int minimizeCost(vector<int>& arr, int& k) {
        return solveTab(arr, k);
    }
};

