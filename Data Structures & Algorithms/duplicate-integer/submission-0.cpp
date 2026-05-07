class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> unMap;
        vector<int>:: iterator it;
        unordered_map<int, int>:: iterator mapIt;
        
        for(it = nums.begin(); it != nums.end(); it++) {
            unMap[*it]++;
        }

        for(mapIt = unMap.begin(); mapIt != unMap.end(); mapIt++) {
            if(mapIt->second > 1) return true;
        }
        return false;
    }
};