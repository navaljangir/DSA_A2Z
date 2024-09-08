class Solution {
  public:
    int solve(vector<int>&height , int n , int index , vector<int>&dp){
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
        if(index+1 < n){
            ans = abs(height[index+1] - height[index]) + solve(height ,n , index+1 ,dp);
        }
        if(index+2 < n ){
            ans = min(ans , abs(height[index+2] - height[index]) + solve(height , n , index+2 , dp));
        }
        return dp[index] = ans;
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1 , -1);
        // Code here
        return solve(height, height.size() , 0 , dp);
    }
};


//tabulation 
class Solution {
  public:
    int solveTab(vector<int>&height) {
        int n = height.size();
        vector<int> dp(n+2 , 1e9);
        dp[n-1]=0;
        for(int i= n-2 ; i>=0; i--){
            dp[i] = abs(height[i] - height[i+1]) + dp[i+1];
            if(i+2<n){
                dp[i] = min(dp[i] , abs(height[i] - height[i+2]) + dp[i+2]);
            }
        }
        return dp[0];
    }
    int minimumEnergy(vector<int>& height, int n) {
        return solveTab(height);
    }
};

//space optimized
 class Solution {
  public:
    int solveTab(vector<int>&height) {
        int n = height.size();
        int next1= 0 ;
        int next2 =0 ;
        for(int i= n-2 ; i>=0; i--){
           int curr = abs(height[i] - height[i+1]) + next1;
            if(i+2<n){
               curr= min(curr , abs(height[i] - height[i+2]) + next2);
            }
            next2 = next1; 
            next1  = curr;
        }
        return next1;
    }
    int minimumEnergy(vector<int>& height, int n) {
        return solveTab(height);
    }
};
