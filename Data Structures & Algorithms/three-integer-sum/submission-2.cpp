class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int i = 0;
        while(i < nums.size()-2) {
            if(i != 0 && nums[i] == nums[i-1]) {
                i++;
                continue;
            }
            int start = i+1, end = nums.size()-1;
            int target = -nums[i];
            
            while(start < end) {
                if(nums[start]+nums[end] < target) start++;
                else if(nums[start]+nums[end] > target) end--;
                else {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while(start < end && nums[start] == nums[start-1]) start++;
                    while(start < end && nums[end] == nums[end+1]) end--;
                }
            }
            i++;
        }
        return ans;
    }
};
