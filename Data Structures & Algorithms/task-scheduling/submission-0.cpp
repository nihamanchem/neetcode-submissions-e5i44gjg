class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> charTrack(26,0);
        for(char c:tasks) charTrack[c-'A']++;
        int maxFreq = *max_element(charTrack.begin(), charTrack.end());
        int numOfEndNotes=0;
        for(int i =0;i<charTrack.size();i++){
            if(charTrack[i]==maxFreq) numOfEndNotes++;
        }
        return max((maxFreq-1)*(n+1) + numOfEndNotes, (int)tasks.size());
    }
};
