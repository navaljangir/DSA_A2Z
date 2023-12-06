class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        int n = s.length();
        priority_queue<pair<int,char>> pq;
        for(int i =0 ; i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]>(n+1)/2){
                return "";
            }
        }
        for(auto i : mp){
            pq.push({i.second ,i.first});
        }
        string str = "";
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            if(str.length()>0 && str[str.length()-1]==p.second && !pq.empty()){
                auto p1 = pq.top();
                pq.pop();
                str+=p1.second;
                p1.first--;
                pq.push(p);
                if(p1.first>0){
                    pq.push(p1);
                }
            }else{
            str +=p.second;
            p.first--;
            // pq.pop();
            if(p.first>0){
            pq.push(p);
            }
            }
        }
    return str;
    }
};
