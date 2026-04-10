class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> helpMap;
        for(string s: strs){
            string key = s;
            sort(key.begin(), key.end());
            helpMap[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& [key,value]: helpMap){
            result.push_back(move(value));
        }
        return result;
    }
};
