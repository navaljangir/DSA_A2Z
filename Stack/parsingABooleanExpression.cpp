
class Solution {
public:
    bool parseBoolExpr(string expression) {
        bool ans =0 ;
        stack<char> st;
        for(int i=0 ; i < expression.size();i++){
            if(expression[i]==')'){
                char ch1 = st.top();
                st.pop();
                char ch2 = st.top();
                st.pop();
                char toPush = 'f';
                if(ch2=='!'){
                    if(ch1=='f'){
                        toPush = 't';
                    }else{
                        toPush = 'f';
                    }
                }else{
                    st.push(ch2);
                    st.push(ch1);
                    vector<int> v;
                    while(!st.empty() && st.top()!='&' && st.top()!='|'){
                        char ch = st.top();
                        ch=='f' ? v.push_back(0) : v.push_back(1);
                        st.pop();
                    }
                    char op=  st.top();
                    st.pop();
                    int num = v[0];
                    if(op=='&'){
                        for(auto i : v){
                            num = num & i;
                        }
                    }else{
                        for(auto i : v){
                            num = num | i;
                        }
                    }
                    num==1 ? toPush = 't' : toPush = 'f';
                }   
                    toPush =='t' ? ans= 1 :  ans= 0;
                    if(!st.empty()){
                        st.push(toPush);
                    }
            }else if(expression[i]!='(' && expression[i]!=','){
                st.push(expression[i]);
            }
        }
        return ans;
    }
};
