class Solution {
public:
    char toLowerCase(char c) {
        return (c >= 65 && c <= 90) ? c + 32 : c;
    }
    bool isNotAlphanumeric(char c) {
        return (
            c < 48 
            || (c > 57 && c < 65) 
            || (c > 90 && c < 97) 
            || (c > 122)
        );
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i < j) {
            while(isNotAlphanumeric(s[i]) && i < j) i++;
            while(isNotAlphanumeric(s[j])  && i < j) j--;
            if(i >= j) break;
            if(toLowerCase(s[i]) != toLowerCase(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
