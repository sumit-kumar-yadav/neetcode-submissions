class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        unordered_map<char,int> freqS1, freqS2;

        for(int i = 0; i < s1.size(); i++) freqS1[s1[i]]++;

        int l = 0;
        for(int r = 0; r < s2.size(); r++) {
            freqS2[s2[r]]++;

            while(freqS2[s2[r]] > freqS1[s2[r]]) {
                freqS2[s2[l]]--;
                l++;
            }

            int currWindowSize = r - l + 1;
            if(currWindowSize == s1.size()) return true;
        }

        return false;
    }
};