class Solution {
public:
    static bool compare(pair<int,int>& a, pair<int,int>& b) {
        return a.second < b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) freq[nums[i]]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&compare)> maxHeap(compare);

        for(auto it = freq.begin(); it != freq.end(); it++) {
            maxHeap.push({it->first, it->second});
        }

        vector<int> output;
        while(k--) {
            output.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return output;
    }
};
