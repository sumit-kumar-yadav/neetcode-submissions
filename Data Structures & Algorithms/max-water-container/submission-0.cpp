class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size()-1;
        int maxWater = 0;
        while(i < j) {
            int w = j-i;
            int h = min(heights[i], heights[j]);
            int currWater = w * h;
            if(currWater > maxWater) maxWater = currWater;
            
            if(heights[i] < heights[j]) i++;
            else if(heights[i] > heights[j]) j--;
            else {
                i++;
                j--;
            }
        }
        return maxWater;
    }
};
