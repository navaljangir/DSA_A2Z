class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool completed = true;
        vector<int> v;
        int row =0 ;
        int maxCol = mat[0].size()-1;
        int maxRow = mat.size()-1;
        bool dir = true;
        int col = 0;
        while(completed){
            if(row==maxRow && col==maxCol){
                v.push_back(mat[row][col]);
                break;
            }
            if(dir==false){
                while(row<maxRow && col>0){
                    v.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                v.push_back(mat[row][col]);
                if(col==0 && row!=maxRow){
                    row++;
                }else{
                    col++;
                }
                dir=true;
            }else{
                while(row>0 && col<maxCol){
                    v.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                v.push_back(mat[row][col]);
                if(row==0 && col!=maxCol){
                    col++;
                }else {
                    row++;
                }
                dir =false;
            }
        } 
        return v;
    }
};
