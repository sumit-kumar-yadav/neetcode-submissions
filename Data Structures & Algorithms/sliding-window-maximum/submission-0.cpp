class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxPq;
        for(int i = 0; i < k; i++) maxPq.push({nums[i], i}); // Sort on basis of element

        vector<int> output;
        output.push_back(maxPq.top().first);
        
        for(int i = k; i < nums.size(); i++) {
            maxPq.push({nums[i], i});
            while(maxPq.top().second < i-k+1) maxPq.pop();
            output.push_back(maxPq.top().first);
        }
        return output;
    }
};
