class Solution {
public:
    bool isValidSubstring(unordered_map<char, int>& sFreq, unordered_map<char, int>& tFreq) {
        if(sFreq.size() < tFreq.size()) return false;
        for(unordered_map<char, int>::iterator it = tFreq.begin(); it != tFreq.end(); it++) {
            if(it->second > sFreq[it->first]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> sFreq, tFreq;
        for(int i = 0; i < t.size(); i++) tFreq[t[i]]++;

        int l = 0, r = 0;
        int windowStart = -1, windowEnd = -1;

        while(r < s.size()) {
            sFreq[s[r]]++;
            bool isValidWindow = isValidSubstring(sFreq, tFreq);
            if(isValidWindow) {
                // Shrink window if possible
                while(l < r && (tFreq.count(s[l]) <= 0 || sFreq[s[l]]-1 >= tFreq[s[l]])) {
                    sFreq[s[l]]--;
                    l++;
                }
                // Update window boundary
                if(windowStart == -1 || windowEnd-windowStart+1 > r-l+1) {
                    windowStart = l;
                    windowEnd = r;
                }
                sFreq[s[l]]--;
                l++;
            }
            r++;
        } 
        return windowStart == -1 ? "" : s.substr(windowStart, windowEnd-windowStart+1);
    }
};