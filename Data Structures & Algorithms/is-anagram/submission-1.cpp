class Solution {
public:
    bool isAnagram(string s, string t) {
        int ls = s.size(), ts = t.size();
        if(ls != ts) return false;  
        else if(ls == 0 || ts == 0) return true;

        unordered_map<char, int> freq;
        for(int i = 0; i < ls; i++) {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        unordered_map<char, int>:: iterator it;
        for(it = freq.begin(); it != freq.end(); it++) {
            if(it->second != 0) return false;
        }
        return true;
    }
};
