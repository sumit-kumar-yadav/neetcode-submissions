class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while(left <= right) {
            int mid = (right + left)/2;
            if(nums[mid] == target) return mid;
            
            if(nums[mid] <= nums[right]) { // Right half is sorted
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
            else { // Left half is sorted
                if(target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};