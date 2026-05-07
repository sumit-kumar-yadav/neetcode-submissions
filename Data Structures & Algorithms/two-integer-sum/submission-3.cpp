class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int repeatedVal = false;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i]) > 0 && 2*nums[i] == target) repeatedVal = true;
            mp[nums[i]] = i;
        }

        vector<int> output;
        for(int i = 0; i < nums.size(); i++) {
            if(2*nums[i] == target && !repeatedVal) {
                continue;
            }
            else if(mp.count((target - nums[i])) > 0) {
                output.push_back(i);
                output.push_back(mp[(target - nums[i])]);
                return output;
            }
        }
        
    }
};
