//Question Link : https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
//Memoization 
class Solution {
  public:
    int mod= 1e9+7;
    int solve(int i ,  int sum ,   vector<int>&arr , vector<vector<int>>&dp){
        if(sum<0){
            return 0;
        }
        if(i>=arr.size()){
            if(sum==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int ans1 = solve(i+1 , sum-arr[i] , arr ,dp);
        int ans2 = solve(i+1 , sum ,arr , dp);
        return dp[i][sum] = (ans1 + ans2)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum =0 ; 
        for(auto i : arr){
            sum+=i;
        }
        sum-=d;
        if(sum<0){
            return 0;
        }
        if(sum%2==1){
            return 0;
        }
        sum=sum/2;
        vector<vector<int>> dp(n , vector<int>(sum+1 , -1));
        return solve(0 , sum , arr , dp);
    }
};

//Tabulation 
class Solution {
  public:
    int mod= 1e9+7;
    int solve(int i ,  int sum ,   vector<int>&arr , vector<vector<int>>&dp){
        if(sum<0){
            return 0;
        }
        if(i>=arr.size()){
            if(sum==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int ans1 = solve(i+1 , sum-arr[i] , arr ,dp);
        int ans2 = solve(i+1 , sum ,arr , dp);
        return dp[i][sum] = (ans1 + ans2)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum =0 ; 
        for(auto i : arr){
            sum+=i;
        }
        sum-=d;
        if(sum<0){
            return 0;
        }
        if(sum%2==1){
            return 0;
        }
        sum=sum/2;
        vector<vector<int>> dp(n , vector<int>(sum+1 , -1));
        return solve(0 , sum , arr , dp);
    }
};
