//
class Solution {
public:
    int solve(int i , int j , string&s1 , string&s2 , vector<vector<int>>&dp){
        if(i>=s1.length() ){
            int sum =0 ; 
            for(int k = j ; k < s2.length();k++){
                sum+=s2[k];
            }
            return sum;
        }
        if(j>=s2.length()){
            int sum =0 ; 
            for(int k = i ; k < s1.length();k++){
                sum+=s1[k];
            }
            return sum;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int isEqual= 1e9;
        int notEqual = 1e9;
        if(s1[i]==s2[j]){
            isEqual = solve(i+1, j+1 , s1 ,s2, dp);
        }else{
         int deleteFrom1 = s1[i] +solve(i+1, j , s1, s2 , dp);
         int deleteFrom2 = s2[j] + solve(i, j+1 , s1, s2 , dp);
         notEqual = min(deleteFrom1 , deleteFrom2);
         
        }
        return dp[i][j] = min(isEqual , notEqual);
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length()+1 , vector<int>(s2.length() , -1));
     return solve(0,0 , s1 , s2 , dp);   
    }
};

//Tabulation

class Solution {
public:
    int minDeleteSum(string s1 ,string s2){
        vector<vector<int>> dp(s1.length()+1 ,vector<int>(s2.length()+1 , 0));
        for(int j= 0 ; j <s2.length();j++){
                int sum =0 ; 
            for(int k = j ; k<s2.length();k++){
                sum+=s2[k];    
            }
            dp[s1.length()][j] = sum;
        }
          for(int j= 0 ; j <s1.length();j++){
                int sum =0 ; 
            for(int k = j ; k<s1.length();k++){
                sum+=s1[k];    
            }
            dp[j][s2.length()] = sum;
        }
        for(int i = s1.length()-1; i>=0;i--){
            for(int j = s2.length()-1; j>=0; j--){
                int isEqual= 1e9;
                int notEqual = 1e9;
                if(s1[i]==s2[j]){
                    isEqual =dp[i+1][j+1];
                }else{
                int deleteFrom1 = s1[i] +dp[i+1][j];
                int deleteFrom2 = s2[j] + dp[i][j+1];
                notEqual = min(deleteFrom1 , deleteFrom2);
                }
                dp[i][j] = min(isEqual , notEqual);
            }
        }
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
     return minDeleteSum(s1,s2);
    }
};


//Space optimisation 
