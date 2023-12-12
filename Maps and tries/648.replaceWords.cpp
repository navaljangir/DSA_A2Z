class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, bool>mp;
        vector<string> str;
        for(auto i : dictionary){
            mp[i]=true;
        }
        for(int i = 0 ; i<sentence.length(); i++){
            string s = "";
            bool found =false;
            int j = i;
            while(j<sentence.length() && sentence[j]!=' '){
                if(mp.find(s)!=mp.end() && found==false){
                    found = true;
                    str.push_back(s);
                }
                s+=sentence[j];
                j++;
            }
            if(found==false){
                str.push_back(s);
            }   
            i=j;
        }
        string ans ="";
        for(int i =0 ; i <str.size()-1; i++){
            ans+=str[i];
            ans+=' ';
        }
        ans+=str[str.size()-1];
        return ans;
    }

};
