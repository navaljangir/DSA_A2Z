//Memoization
class Solution {
  public:
    int solve(vector<vector<int>>&arr , int i ,int prev , vector<vector<int>>&dp){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int ans = INT_MIN;
        for(int k =0; k < arr[i].size();k++){
            if(k!=prev){
                ans =max(ans , arr[i][k] + solve(arr,  i+1 , k, dp)); 
            }
        }
        return dp[i][prev+1] = ans;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        int size= arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(size+1 ,  vector<int>(m +2, -1));
        return solve(arr , 0 , -1 ,dp);
        // return 0 ;
    }
};

//Tabulation
class Solution {
  public:
    int solveTab(vector<vector<int>>&arr){
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n+1 , vector<int>(m , -1));
        for(int j =0 ; j < m ; j++){
            dp[n][j] = 0;
        }
        for(int i = n-1; i>=0;i--){
            for(int j = 0 ; j < m;j++){
                for(int k = 0 ; k < m ; k++){
                    if(j!=k){
                        dp[i][j] = max({dp[i][j] ,arr[i][k] + dp[i+1][k]});
                    }
                }
            }    
        }
        int ans = INT_MIN;
        for(int i =0; i < m;i++){
            ans = max(ans , dp[0][i]);
        }
        return ans;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        return solveTab(arr);
    }
};

//Space optimized
class Solution {
  public:
    int spaceOpti(vector<vector<int>>&arr){
        int n = arr.size();
        int m = arr[0].size();
        // vector<int> curr(m , -1);
        vector<int> next(m , 0);
        for(int i = n-1; i>=0;i--){
            vector<int> curr(m+1 , -1);
            for(int j = 0 ; j < m;j++){
                for(int k = 0 ; k < m ; k++){
                    if(j!=k){
                        curr[j] = max({curr[j] ,arr[i][k] + next[k]});
                    }
                }
            }    
            next =curr; 
        }
        int ans = INT_MIN;
        for(int i =0; i < m;i++){
            ans = max(ans ,next[i]);
        }
        return ans;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        return spaceOpti(arr);
    }
};
