//problem link : https://leetcode.com/problems/n-queens/
class Solution {
public:
    vector<vector<string>> ans;
    // string str; 
    bool checkIfPossible(int row , int col , vector<vector<char>>&board){
        // int i =row;
        // int j = col;
        for(int i = 0 ; i < board[0].size() ;i++){
            if(board[row][i]=='Q'){
                return false;
            }
        }
        for(int i =0 ; i < board.size();i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        int i = row; 
        int j = col;
        while(i<board.size() && j<board.size()){
            if(board[i][j]=='Q'){
                return false;
            }
            i++;
            j++;
        }
        i = row; 
        j = col;
        while(i>=0 && j<board.size()){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        i = row; 
        j = col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        i = row; 
        j = col;
        while(i<board.size() && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int row , int col , int n ,int kept , vector<vector<char>> &board){
        if(kept==n){
            vector<string> v;
            for(int i =0 ; i < board.size(); i++){
                string str ="";
                for(int j = 0 ; j <board.size();j++){
                    str+=board[i][j];
                }
                v.push_back(str);
            }
            ans.push_back(v);    
            return; 
        }
        if(row>=n){
            return;
        }
        if(col>=n){
            return;
        }
        if(checkIfPossible(row , col , board)){
            board[row][col] = 'Q';
            solve(row+1 , 0 , n , kept+1 , board);
            board[row][col]  = '.';
        }
        solve(row , col+1 , n  ,kept , board);
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n , vector<char>(n , '.'));
        solve(0 , 0 , n , 0 , board);
        return ans;
    }
};
