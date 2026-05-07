class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0; i < strs.size(); i++) {
            s += to_string(strs[i].size()) + "#" + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while(i < s.size()) {
            // Find the size of str
            int j = i;
            while(s[j] != '#') j++;
            int l = stoi(s.substr(i, j-i));

            i = j+1;
            strs.push_back(s.substr(i, l));
            i += l;
        }
        return strs;
    }
};
