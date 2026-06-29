class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = "";
        for(string str: strs){
            res=res+to_string(str.length())+"#"+str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if(s.length()==0) return {};
        int i=0;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#') j++;
            int len = stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1,len));
            i=j+1+len;
        }
        return ans;
    }
};
