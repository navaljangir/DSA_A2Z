class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a!=0)  pq.push({a , 'a'});
        if(b!=0)  pq.push({b,'b'});
        if(c!=0)  pq.push({c, 'c'});
        string str="";
        while(pq.size()>=2){
            auto p = pq.top();
            pq.pop();
            auto p1= pq.top();
            pq.pop();
            if(p.first-p1.first>2){
                str+=p.second;
                p.first--;
                if(p.first>0){
                    str+=p.second;
                    p.first--;
                }
                str+=p1.second;
                p1.first--;
            }else{
                str+=p.second;
                p.first--;
                if(p.first>0){
                    str+=p.second;
                    p.first--;
                }
                str+=p1.second;
                p1.first--;
                if(p1.first>0){
                    str+=p1.second;
                    p1.first--;
                }
            }
            if(p.first>0){
                pq.push(p);
            }
            if(p1.first>0){
                pq.push(p1);
            }
        }
        if(!pq.empty()){
             auto p = pq.top();
            cout<<p.first<<" ";
             pq.pop();
             if(p.first>=2){
                 str+=p.second;
                 str+=p.second;
             }else{
                 str+=p.second;
             }
        }
        return str;
    }
};


//Solution 2
class node{
    public:
    char data;
    int count;
    node(char ch,  int c){
        count= c;
        data =ch;
    }
};
class compare{
    public: 
    bool operator()(node a , node b){
        return a.count<b.count;
    }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<node,vector<node> , compare> pq;
        if(a!=0) {
            node temp('a' , a);
            pq.push(temp);
        }
        if(b!=0){
            node temp('b' , b);
            pq.push(temp);
        }
        if(c!=0){
            node temp('c' , c);
            pq.push(temp);
        }
        string str="";
        while(pq.size()>=2){
            auto p = pq.top();
            pq.pop();
            auto p1= pq.top();
            pq.pop();
            if(p.count>=2){
                str+=p.data;
                str+=p.data;
                p.count-=2;
            }else{
                str+=p.data;
                p.count-=1;
            }
            if(p1.count>=2 && p1.count>=p.count){
                str+=p1.data;
                str+=p1.data;
                p1.count-=2;
             }else{
                 str+=p1.data;
                p1.count-=1;
             }
            
            if(p.count>0){
                pq.push(p);
            }
            if(p1.count>0){
                pq.push(p1);
            }
        }
        if(!pq.empty()){
             auto p = pq.top();
             pq.pop();
             if(p.count>=2){
                 str+=p.data;
                 str+=p.data;
             }else{
                 str+=p.data;
             }
        }
        return str;
    }
};
