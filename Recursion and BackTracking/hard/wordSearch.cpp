//problem link : https://leetcode.com/problems/word-search/

class Solution {
public:
    
    bool solve(int i , int j , int index , string &s , vector<vector<char>> & board ,vector<vector<int>>& visited ){
        if(index>=s.size()){
            return true;
        }
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0){
            return false;
        }
        if(visited[i][j]==1){
            return false;
        }
        bool ans = false;
        visited[i][j] = 1; 
        if(board[i][j]==s[index]){
            ans = ans || solve(i+1 , j , index+1 , s,  board ,visited);
            ans = ans || solve(i -1 , j , index+1 , s, board ,visited);
            ans = ans || solve(i,  j+1 , index+1 , s ,board ,visited);
            ans = ans || solve(i , j-1 , index+1 , s, board ,   visited);
        }
         visited[i][j]= 0;
        return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0 ; i <board.size() ; i++){
            for(int j = 0 ; j <board[0].size();j++){
            vector<vector<int>> visited(board.size() , vector<int>(board[0].size() , 0 ));
            bool ans = solve(i , j , 0 , word, board ,visited);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
};
