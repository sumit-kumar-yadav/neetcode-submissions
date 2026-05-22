class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int linkedIndex = abs(nums[i])-1;
            if(nums[linkedIndex] < 0) return abs(nums[i]);
            nums[linkedIndex] *= -1;
        }
        return nums[0];
    }
};
