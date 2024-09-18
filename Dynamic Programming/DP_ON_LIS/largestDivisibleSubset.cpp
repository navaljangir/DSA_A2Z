//Question Link : https://leetcode.com/problems/largest-divisible-subset/description/




//Optimized 
// T.C => O(n^2)
// S.C => O(n)

class Solution {
public:
    vector<int> solve(vector<int>&nums){
        vector<int> ans;
        int n= nums.size();
        vector<int> v(n , 1);
        int maxi  =0;

       int maxiIndex =0;
       for(int i = n-1;i>=0;i--){
        for(int j = i+1;j<n;j++){
            if(nums[j] %nums[i] ==0){
                v[i] = max(v[i] , 1+ v[j]);
                if(maxi<v[i]){
                maxi = max(maxi , v[i]);
                maxiIndex = i;
                }
            }
        }
       }

       ans.push_back(nums[maxiIndex]);
       int j = maxiIndex+1;
       maxi--;
       int prev = maxiIndex;
       while(j<n){
        if(nums[j]%nums[prev]==0 && v[j]==maxi){
            prev = j ;
            maxi--;
            ans.push_back(nums[j]);
        }
        j++;
       }
        return ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        return solve(nums);
        // return ans;
    }
};
