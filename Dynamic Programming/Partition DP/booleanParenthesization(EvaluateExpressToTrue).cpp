//Memoization 
#define ll long long
class Solution{
    int mod = 1003;
public:
    int solve(int &n , int i , int j , int isTrue , string &s , vector<vector<vector<ll>>>&dp){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(isTrue){
                return s[i]=='T';
            }else{
                return s[i]=='F' ;
            }
        }
        if(dp[i][j][isTrue]!=-1){
            return dp[i][j][isTrue];
        }
        long long ways = 0;
        for(int k = i+1;k<j;k= k+2){
            int leftTrue = solve(n , i , k-1,  1 , s, dp);
            int leftFalse = solve(n , i , k-1, 0 , s, dp);
            int rightFalse = solve(n , k+1 , j , 0 , s, dp);
            int rightTrue = solve(n , k+1 , j , 1, s ,dp);
            if(s[k]=='&'){
                if(isTrue){
                    ways =  (ways + (leftTrue * rightTrue) % mod)%mod;   
                }else{
                    ways = (ways + ((leftFalse * rightFalse) % mod + ((rightTrue * leftFalse ) % mod + (rightFalse * leftTrue)%mod)%mod)%mod)%mod;
                }
            }else if(s[k]== '|'){
                if(isTrue){
                    ways = (ways + ((leftTrue * rightTrue) % mod + ((rightTrue * leftFalse )%mod + (rightFalse * leftTrue)%mod)%mod)%mod)%mod;
                }else{
                    ways = (ways + (leftFalse * rightFalse)%mod)%mod;
                }
            }else{
                if(isTrue){
                    ways = (ways + (leftTrue * rightFalse)%mod + (rightTrue * leftFalse)%mod)%mod;
                }else{
                    ways = (ways + (leftFalse* rightFalse)%mod + (leftTrue * rightTrue)%mod)%mod;
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int countWays(int n, string s){
        // code here
        vector<vector<vector<ll>>> dp(s.length() , vector<vector<ll>>(s.length() , vector<ll>(2 , -1)));
        return solve(n , 0, n-1 , 1 , s ,dp);
        
    }
};
