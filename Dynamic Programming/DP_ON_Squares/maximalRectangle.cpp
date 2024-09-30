class Solution {
public:
    vector<int>  findPrevSmaller(vector<int> &v){
        vector<int> ans(v.size());
        stack<int> st;
        for(int i =0 ; i < v.size();i++){
            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmaller(vector<int> &v){
        int n = v.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    
    int solve(vector<int> &v){
        vector<int> leftSmaller = findPrevSmaller(v);
        vector<int> rightSmaller=  nextSmaller(v);
        int ans = 0;
        for(int i =0 ;i < v.size();i++){
            ans = max(ans , v[i] * (rightSmaller[i] - leftSmaller[i] - 1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v(matrix[0].size() ,0);
        int ans=0 ;
        for(int i=0 ; i<  matrix.size();i++){
            for(int j = 0 ; j < matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    v[j]++;
                }else{
                    v[j] =0;
                }
            }
            int val = solve(v);
            ans = max(ans , val);
        }
        return ans;
    }
};
