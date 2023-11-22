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
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        map<int,vector<pair<int,int>>> mp;
        for(int i = 0; i<nums.size();i++){
            for(int j =0;j< nums[i].size();j++){
                mp[i+j].push_back({i,j});
            }
        }
        for(auto i : mp){
            vector<pair<int,int>> v = i.second;
            for(int j = v.size()-1;j>=0;j--){
                ans.push_back(nums[v[j].first][v[j].second]);
            }
        }
        return ans;
    }
};
