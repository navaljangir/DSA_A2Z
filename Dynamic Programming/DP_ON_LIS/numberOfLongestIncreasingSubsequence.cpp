//Question Link : 


// Memoized
class Solution {
public:
    
    pair<int,int> solve(vector<int>&nums , int index , int prev , vector<vector<pair<int,int>>> &dp){
        if(index>=nums.size()){
            return {0 ,1};
        }
        if(dp[index][prev+1].first!=-1){
            return dp[index][prev+1];
        }
        pair<int,int> ans1 = {0, 0};
        if(prev==-1 || nums[index]>nums[prev]){
            pair<int,int> p = solve(nums , index+1 , index , dp);
            ans1 =  {1+ p.first , p.second};
        }
        pair<int,int> ans2 = solve(nums , index+1 , prev , dp);
        pair<int,int> ans ;
        if(ans1.first>ans2.first){
            ans = ans1;
        }else{
            ans = ans2;
        }
        if(ans1.first==ans2.first){
            ans.second = ans1.second + ans2.second;
        }
        return dp[index][prev+1] = ans;
    }
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<pair<int,int>>> dp(nums.size() ,  vector<pair<int,int>> (nums.size() , {-1,-1}));
        return solve(nums , 0 , -1, dp).second;
    }
};
//Opimized 
class Solution {
public:
    int solve(vector<int>&nums){
        int n = nums.size();
        int ans =0;
        int maxi = 1;
        vector<int> v(n,1);
        vector<int> count(n , 1);
        for(int i= n-1; i>=0;i--){
            for(int j = i+1; j<n;j++){
                if(nums[i]<nums[j]){
                    if(v[i]==1+v[j]){
                        count[i] +=count[j];
                    }else if(v[i]<1+v[j]){
                        count[i] = count[j];
                        v[i] = 1+ v[j];
                        maxi= max(maxi , v[i]);
                    }
                }
            }
        }
        for(int i =0 ; i < n;i++){
            if(v[i]==maxi){
                ans+=count[i];
            }
        }
        return ans;
    }
    int findNumberOfLIS(vector<int>& nums) {
        return solve(nums);
    }
};
