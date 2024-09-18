//Longest String Chain 
//Question Link : https://leetcode.com/problems/longest-string-chain/
//Memoization 
class Solution {
public:
    static bool comp(string &a , string&b){
        if(a.size()==b.size()){
            return a<b;
        }
        return (int)a.size()<(int)b.size();
    }
    bool check(string &a , string&b){
        int i =0 ;
        int j  =0 ;
        int count =0 ;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                if(count<1){
                    count++;
                    j++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    int solve(vector<string>&words ,int index , int prev , vector<vector<int>>&dp){
        if(index>=words.size()){
            return 0;
        }
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int ans1 =0;
        if(prev==-1 || (check(words[prev] ,  words[index]) && words[prev].size()+1==words[index].size())){
            ans1 = 1 + solve(words , index+1 , index , dp);
        }
        int ans2 = solve(words , index+1 , prev , dp);
        return dp[index][prev+1] = max(ans1 , ans2);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() , comp);
        vector<vector<int>> dp(words.size() , vector<int>(words.size()+1 , -1));
        return solve(words ,0 , -1, dp);
    }
};

// Optimized 
class Solution {
public:
    static bool comp(string &a , string&b){
        if(a.size()==b.size()){
            return a<b;
        }
        return (int)a.size()<(int)b.size();
    }
    bool check(string &a , string&b){
        int i =0 ;
        int j  =0 ;
        int count =0 ;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                if(count<1){
                    count++;
                    j++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    int solve(vector<string>&words){
        int n = words.size();
        vector<int> dp(n , 1);
        int ans =1;
        for(int i = n-1;i>=0;i--){
            for(int j= i+1; j<n;j++){
               if(check(words[i] ,  words[j]) && words[i].size()+1==words[j].size()){
                dp[i] = max(dp[i] ,1+ dp[j]);
                ans = max(dp[i] , ans);
               }
            }
        }
        return ans;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() , comp);
        return solve(words );
    }
};
