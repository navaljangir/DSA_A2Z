//problem link : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    public:
    vector<string> ans;
    void solve(vector<vector<int>>&m ,int i , int j , string str , vector<vector<int>>&visited){
         if(i<0 || j<0 || j>=m.size() || i>=m.size()){
            return ;
        }
        
        if(m[i][j]==0 || visited[i][j]==1){
            return ;    
        }
        if(i==m.size()-1 && j == m.size()-1){
            ans.push_back(str);
            return;
        }
       
        visited[i][j]= 1; 
        solve(m , i +1 , j , str + 'D' , visited);
        solve(m , i -1 , j , str+'U' , visited);
        solve(m , i , j +1 , str + 'R' , visited);
        solve(m , i ,  j-1 , str+'L' , visited);
        visited[i][j]= 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> visited(m.size() , vector<int>(m.size()));
        solve(m , 0 ,0  , "" , visited);
        return ans;
    }
};
