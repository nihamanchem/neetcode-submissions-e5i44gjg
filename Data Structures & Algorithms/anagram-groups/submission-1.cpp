class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> tracker;
        for(string s:strs){
            string x = s;
            sort(x.begin(),x.end());
            tracker[x].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &it:tracker){
            ans.push_back(it.second);
        }
        return ans;
    }
};
