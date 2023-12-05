class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int , pair<int,int>>>> pq;
        for(int i= 0; i <arr.size();i++){
            pq.push({arr[i][0] ,{ i , 0}});
        }
        while(!pq.empty()){
        auto p= pq.top();
        pq.pop();
        int num =p.first;
        int r = p.second.first;
        int c = p.second.second;
        ans.push_back(num);
        if(c+1<K){
            pq.push({arr[r][c+1],{r, c+1}});
        }
        }
        return ans;
    }
};
