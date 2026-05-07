class Solution {
public:
    // Water trapped at index i will decided by min(leftMaxHeight, rightMaxHeight)
    // So, for each index if we store the leftMaximum height and rightMaximum height
    // then we can solve it.
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        
        vector<int> lMax(n, 0);
        vector<int> rMax(n, 0);

        lMax[0] = height[0];
        for(int i = 1; i < n; i++) lMax[i] = max(lMax[i-1], height[i]);

        rMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) rMax[i] = max(rMax[i+1], height[i]);

        int totalWater = 0;
        for(int i = 0; i < n; i++) {
            int boundaryHt = min(lMax[i], rMax[i]);
            totalWater += (boundaryHt - height[i]);
        }
        return totalWater;
    }
};
