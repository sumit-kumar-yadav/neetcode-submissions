class Solution {
public:
    // For each index, if we can find the nearest smallest left & right height,
    // then we can find the rect area covered for that index.
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftNearestSmallest(n);
        vector<int> rightNearestSmallest(n);
        stack<int> st;

        // Calculate and save index of left nearest smallest el than ith el using stack
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            leftNearestSmallest[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        // Empty the stack to reuse it
        while(!st.empty()) st.pop();

        // Calculate and save index of right nearest smallest el than ith el using stack
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            rightNearestSmallest[i] = !st.empty() ? st.top() : n;  // Note: Default right boundary will be n here
            st.push(i);
        }

        // Solve actual question 
        int maxRectArea = 0;
        for(int i = 0; i < n; i++) {
            int width = rightNearestSmallest[i] - leftNearestSmallest[i] - 1;
            int area = heights[i] * width;
            maxRectArea = max(maxRectArea, area);
        }
        return maxRectArea;
    }
};
