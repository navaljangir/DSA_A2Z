//code 2  with o(n)space. find the optimized code below
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(int i =0 ; i < tasks.size();i++){
            mp[tasks[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i : mp){
            pq.push({i.second , i.first});
        }
        int count = 0 ;
        unordered_map<char,int> lastUsed;
        for(char ch = 'A';ch<='Z';ch++){
            lastUsed[ch] = -(n+1);
        }
        while(!pq.empty()){
                vector<pair<int,char>> v;
                while(!pq.empty() && count-lastUsed[pq.top().second]<=n){
                    v.push_back(pq.top());
                    pq.pop();
                }
                if(!pq.empty()){
                    auto top = pq.top();
                    pq.pop();
                    lastUsed[top.second] = count++;
                    if(top.first-1>0){
                        pq.push({top.first-1 , top.second});
                    }
                }else{
                    count++;
                }
                for(auto i : v){
                    pq.push(i);
                }
        }
        return count;
    }
};

//optimized code
typedef pair<int,int> pii;
class Solution {
public:
    bool comp(pair<int,int>&a , pair<int,int>&b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first> b.first;
    }
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto i : tasks){
            mp[i]++;
        }
        priority_queue<pii,  vector<pii> , greater<pii>> pq;
        for(auto i: mp){
            pq.push({0 , i.second});
        }
        int ans=0 ;
        while(!pq.empty()){
            auto top= pq.top();
            if(ans>=top.first){
                pq.pop();
                ans++;
                if(top.second-1>0){
                    pq.push({top.first+n+1 , top.second-1});
                }
            }else{
                ans++;
            }
        }
        return ans;
    }
};
