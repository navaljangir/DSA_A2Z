//REcursion TLE
class Solution {
public:
    int mctFromNonoLeafNodes(int left , int right, map<pair<int,int>,int> &mp){
        if(left==right){
            return 0;
        }
        int ans =INT_MAX;
        for(int i = left; i <right; i++){
            ans = min(ans, mp[{left, i}] * mp[{i+1, right}] + mctFromNonoLeafNodes(left , i , mp) + mctFromNonoLeafNodes(i+1, right ,mp));
        }
        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> mp;
        for(int i =0 ; i <arr.size();i++){
            mp[{i,i}] = arr[i];
            int prevMaxi = arr[i];
            for(int j = i+1; j <arr.size();j++){
                mp[{i,j}]= max(prevMaxi , arr[j]);
                prevMaxi = max(prevMaxi , arr[j]);
            }
        }
        return mctFromNonoLeafNodes(0, arr.size()-1 , mp);
    }
};

//DP 
class Solution {
public:
    int mctFromNonoLeafNodes(int left , int right, map<pair<int,int>,int> &mp ,vector<vector<int>>&dp){
        if(left==right){
            return 0;
        }
        int ans =INT_MAX;
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        for(int i = left; i <right; i++){
            ans = min(ans, mp[{left, i}] * mp[{i+1, right}] + mctFromNonoLeafNodes(left , i , mp,dp) + mctFromNonoLeafNodes(i+1, right ,mp,dp));
        }
        return dp[left][right] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1 ,-1));
        map<pair<int,int>,int> mp;
        for(int i =0 ; i <arr.size();i++){
            mp[{i,i}] = arr[i];
            int prevMaxi = arr[i];
            for(int j = i+1; j <arr.size();j++){
                mp[{i,j}]= max(prevMaxi , arr[j]);
                prevMaxi = max(prevMaxi , arr[j]);
            }
        }
        return mctFromNonoLeafNodes(0, arr.size()-1 , mp,dp);
    }
};

//DP Tabulation 

class Solution {
public:
    int mctFromNonoLeafNodes2(map<pair<int,int> , int> &mp , vector<int>&arr){
        vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1, 0 ));
        for(int left =arr.size()-1 ; left>=0; left--){
            for(int right= 0; right<arr.size(); right++){
                if(left<right){
                    int ans= INT_MAX;
                    for(int i = left; i <right; i++){
                 ans = min(ans, mp[{left, i}] * mp[{i+1, right}] + dp[left][i] + dp[i+1][right]);
                    }
                dp[left][right]= ans;
                }
            }
        }
    return dp[0][arr.size()-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1 ,-1));
        map<pair<int,int>,int> mp;
        for(int i =0 ; i <arr.size();i++){
            mp[{i,i}] = arr[i];
            int prevMaxi = arr[i];
            for(int j = i+1; j <arr.size();j++){
                mp[{i,j}]= max(prevMaxi , arr[j]);
                prevMaxi = max(prevMaxi , arr[j]);
            }
        }
        return mctFromNonoLeafNodes2(mp , arr);
    }
};
