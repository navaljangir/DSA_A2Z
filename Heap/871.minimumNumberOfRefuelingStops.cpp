class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int dist =0 ;
        int fuel = startFuel;
        priority_queue<pair<int,int>> pq;
        int i = 0; 
        int hops =0 ;
        while(true){
            while(i<stations.size()){
                if(stations[i][0]<=fuel+dist){
                    pq.push({stations[i][1], stations[i][0]});
                }else{
                    break;
                }
                i++;
            }
            dist+=fuel;
            fuel =0;
            if(dist>=target){
                return hops;
            }
            if(pq.empty()){
                return -1;
            }
            auto p = pq.top();
            fuel = dist- p.second + p.first;
            dist = p.second;
            pq.pop();
            hops++;
        }
        return hops;
    }
};
