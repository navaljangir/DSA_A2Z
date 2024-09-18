//Question Link : https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1


//Optimized 
class Solution {
  public:
    int solve(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n , 1);
        for(int i = 0 ; i <n;i++){
            for(int  j= i-1; j>=0; j--){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i] , 1+ dp[j]);
                }
            }
        }
        vector<int> v2(n, 0);
        for(int i = n-1;i>=0;i--){
            for(int j = i+1; j<n;j++){
                if(nums[j]<nums[i]){
                    v2[i] = max(v2[i] , 1+ v2[j]);
                }
            }
        }
        int ans=0; 
        for(int i =0 ; i < n;i++){
            if(v2[i]!=0){
                if(dp[i]>=2){
                    ans =max(ans , dp[i] + v2[i]);
                }    
            }
        }
        return ans;
    }
    int LongestBitonicSequence(int n, vector<int> &nums) {
        return solve(nums);
    }
};
//Solution // 4D DP : TLE
class Solution {
  public:
    int solve(vector<int>&nums , int index ,int prev , int taken , int direction , vector<vector<vector<vector<int>>>> &dp){
        if(index>=nums.size()){
            if(direction==1){
                return -1e9;
            }
            return 0;
        }
        if(dp[index][prev+1][taken][direction]!=-1){
            return dp[index][prev+1][taken][direction];
        }
        int ans1 = -1e9;
        if(prev==-1 || (nums[index]>nums[prev] && direction==1)){
            int val = taken==2 ? taken: taken+1; 
            ans1 = 1+ solve(nums , index+1 , index , val , direction ,dp);
        }
        if(prev!=-1 && nums[index]<nums[prev] && direction==1 && taken>1){
            ans1 = max(ans1  , 1+ solve(nums , index+1 , index , taken , 0 , dp));
        }
        int ans2 = -1e9;
        if(prev!=-1 && nums[index]<nums[prev] && direction==0){
            ans2 = 1 + solve(nums , index+1 , index ,taken , direction ,dp);
        }
        int ans3 = solve(nums , index+1 , prev , taken , direction ,dp);
        return dp[index][prev+1][taken][direction] = max({ans1 , ans2 , ans3});
    }
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<vector<vector<vector<int>>>> dp(nums.size() +1 , vector<vector<vector<int>>>(nums.size()+2 , vector<vector<int>>(3,  vector<int>(2, -1))));
        
        int ans = solve(nums , 0, -1 ,0,  1, dp);
        if(ans<0){
            return 0;
        }
        return ans;
    }
};

