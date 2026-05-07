class Solution {
public:
    // Since deciding factor is the min(leftMaxHeight, rightMaxHeight),
    // so we can use 2 pointer approach by inc left or dec right
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        int totalWater = 0;
        int lMax = height[0], rMax = height[n-1];
        int left = 0, right = n - 1;
        while(left < right) {
            lMax = max(lMax, height[left]);
            rMax = max(rMax, height[right]);

            if(lMax < rMax) {
                totalWater += (lMax - height[left]);
                left++;
            } else {
                totalWater += (rMax - height[right]);
                right--;
            }
        }
        return totalWater;
    }
};
