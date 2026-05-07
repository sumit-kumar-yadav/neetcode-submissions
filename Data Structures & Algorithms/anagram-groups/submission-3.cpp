class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> output;

        for(int i = 0; i < strs.size(); i++){
            string word = strs[i];
            sort(word.begin(),word.end());
            map[word].push_back(strs[i]);
        }

        for(auto it = map.begin(); it != map.end(); it++){
            output.push_back(it->second);
        }

        return output;
    }
};


// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> output;
//         int visited[1000] = {0};
//         for(int i = 0; i < strs.size(); i++) {
//             if(visited[i] == 1) continue; 
            
//             unordered_map<char, int> prevFreq;
//             vector<string> ans;
//             ans.push_back(strs[i]);
//             visited[i] = 1;

//             for(int j = 0; j < strs[i].size(); j++) prevFreq[strs[i][j]]++;
//             for(int j = i+1; j < strs.size(); j++) {
//                 if(strs[i].size() != strs[j].size()) continue;
                
//                 unordered_map<char, int> currFreq;
//                 for(int k = 0; k < strs[j].size(); k++) currFreq[strs[j][k]]++;
                
//                 bool isAnagram = true;
//                 for(int k = 0; k < strs[j].size(); k++) {
//                     if(prevFreq.count(strs[j][k]) == 0 || prevFreq[strs[j][k]] != currFreq[strs[j][k]]) {
//                         isAnagram = false;
//                         break;
//                     }
//                 }
//                 if(isAnagram) {
//                     ans.push_back(strs[j]);
//                     visited[j] = 1;
//                 }
//             }
//             output.push_back(ans);
//         }
//         return output;
//     }
// };
