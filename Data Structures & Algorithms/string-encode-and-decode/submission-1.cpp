class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size()==0) return "";
        string s="";
        for(string str:strs){
            s=s+to_string(str.length())+"#"+str;
        }
        return s;
    }

    vector<string> decode(string s) {
        if(s.length()==0) return {};
        vector<string> ans;
        string len="";
        int i=0;
        while(i<s.length()){
            if(s[i]=='#'){
                int wordlen = stoi(len);
                string t="";
                while(wordlen>0){
                    i++;
                    t+=s[i];
                    wordlen--;
                }
                ans.push_back(t);
                len="";
            } else {
                len+=s[i];
            }
            i++;
        }
        return ans;
    }
};
