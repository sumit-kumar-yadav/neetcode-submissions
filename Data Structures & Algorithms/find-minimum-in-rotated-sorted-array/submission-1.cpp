class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size()-1;

        while(left <= right) {
            int mid = right - (right - left)/2;
            if(left == right) return nums[left];
            if(right - left == 1) return min(nums[left], nums[right]);
            
            if(nums[mid] <= nums[right]) right = mid;
            else left = mid;
        }
        return INT_MIN;
    }
};
