// Memoization 
class Solution {
public:
    bool isPalindrome(string &s){
        int i =0 ;
        int j = s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    int solve(int index , string &s , vector<int>&dp){
        if(index>=s.length()){
            return 0;
        }
        int ans = 1e9;
        string str= "";
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i = index ;i<s.length();i++){
            str+=s[i];
            if(isPalindrome(str)){
                ans = min(ans , 1+ solve(i+1 , s , dp));
            }
        }
        return dp[index] = ans;
    }
    int minCut(string s) {
        vector<int> dp(s.length(), -1);
        int ans = solve(0 , s , dp);
        if(ans==1e9){
            return 0;
        }
        return ans-1;
    }
};

//Tabulation
class Solution {
public:
    bool isPalindrome(string &s){
        int i =0 ;
        int j = s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    int solveTab(string &s){
        int n = s.length();
        vector<int> dp(n+1, 1e9);
        dp[n]= 0;
        for(int i = n-1;i>=0;i--){
            string str = "";
            int ans = 1e9;
            for(int j = i;j<s.length();j++){
                str+=s[j];
                if(isPalindrome(str)){
                    ans = min(ans , 1 + dp[j+1]);
                }
            }
            dp[i] = ans;
        }
        return dp[0];
    }
    int minCut(string s) {
        int ans = solveTab(s) ;
        if(ans==1e9){
            return 0;
        }
        return ans-1;
    }
};
