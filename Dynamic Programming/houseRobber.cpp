//Recursion 
class Solution {
public:
    int solvemem(vector<int>& nums , int i , int prev ){
        if(i>=nums.size()){
            return 0;
        }
        int take = 0 ;
        int notTake = 0; 
        if(prev==-1 || prev!=i-1){
            take = nums[i] + solvemem(nums , i+1 ,i); 
        }
        notTake = solvemem(nums , i+1 , prev);
        return  max(take , notTake);
    }
    int rob(vector<int>& nums) {
        return solvemem(nums , 0, -1 );
    }
};


//top down 
class Solution {
public:
    int solvemem(vector<int>& nums , int i , int prev ,vector<vector<int>>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int take = 0 ;
        int notTake = 0; 
        if(prev==-1 || prev!=i-1){
            take = nums[i] + solvemem(nums , i+1 ,i,dp); 
        }
        notTake = solvemem(nums , i+1 , prev,dp);
        return dp[i][prev+1] = max(take , notTake);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() , vector<int>(nums.size(),-1));
        return solvemem(nums , 0, -1 ,dp);
    }
};
