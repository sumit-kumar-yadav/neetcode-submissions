class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> first(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) first[i] = 1;
            else first[i] = first[i-1]*nums[i-1];
        }
        vector<int> last(nums.size());
        for(int j = nums.size()-1; j >= 0; j--) {
            if(j == nums.size()-1) last[j] = 1;
            else last[j] = last[j+1]*nums[j+1];
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) ans.push_back(first[i]*last[i]);
        return ans;
    }
};
