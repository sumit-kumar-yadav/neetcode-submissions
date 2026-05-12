class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int l = 0, r = 0;
        unordered_map<char, int> mp;

        while(r < s.size()) {
            while(mp.count(s[r]) > 0) {
                mp.erase(s[l]);
                l++;
            }
            mp[s[r]]++;
            int currCount = r - l + 1;
            longest = max(longest, currCount);
            r++;
        }
        return longest;
    }
};