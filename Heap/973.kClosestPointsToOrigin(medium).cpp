class Solution {
    typedef pair<double,vector<int>> pvi;
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pvi , vector<pvi> , greater<pvi>> pq;
       for(int i=0 ; i<points.size();i++){
           int num1 = points[i][0] * points[i][0];
            int num2 =points[i][1] * points[i][1];
            double num =( double)(sqrt(num1+num2));
            pq.push({num ,points[i]});
       }
       vector<vector<int>> ans;
       while(!pq.empty() && k>0){
           auto p = pq.top();
           pq.pop();
           ans.push_back(p.second);
           k--;
       }
       return ans;
    }
};
