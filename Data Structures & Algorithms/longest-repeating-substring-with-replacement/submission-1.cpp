class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0, right = 0;
        int maxFreq = 0;
        int longestSubStr = 0;

        while(right < s.size()) {
            freq[s[right]]++;
            
            maxFreq = max(maxFreq, freq[s[right]]);
            int windowSize = right - left + 1;
            int noOfCharToBeReplaced = windowSize - maxFreq;

            if(noOfCharToBeReplaced <= k) {
                longestSubStr = max(longestSubStr, windowSize);
                right++;
            }
            else {
                maxFreq = (freq[s[left]] == maxFreq) ? maxFreq-1 : maxFreq;
                freq[s[left]]--;
                left++;
                right++;
            }
        }

        return longestSubStr;
    }
};
