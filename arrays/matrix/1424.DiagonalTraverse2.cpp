//first intuition TLE (53/56) Passed
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> v;
        int colMax = -1;
        for(auto i :nums){
            int size =i.size()-1;
            colMax = max(colMax,size);
        }
        int maxRow = nums.size()-1;
        for(int row = 0 ;row < nums.size();row++){
            int currCol = 0;
            int currRow = row;
            while(currCol<=colMax && currRow>=0){
                if(currCol<nums[currRow].size()){
                    v.push_back(nums[currRow][currCol]);
                }
                currRow--;
                currCol++;
            }
        }
        for(int i =1;i<=colMax;i++){
            int row = maxRow;
            int col = i;
            while(row>=0 &&col<=colMax){
                if(col<nums[row].size()){
                    v.push_back(nums[row][col]);
                }
                col++;
                row--;
            }
        }
        return v;
    }
};


//Optimised
