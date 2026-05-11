class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& valueArr = store[key];
        int left = 0, right = valueArr.size() - 1;
        
        int possibleIndex = -1;
        while(left <= right) {
            int mid = (left + right)/2;
            if(valueArr[mid].first == timestamp) return valueArr[mid].second;

            if(valueArr[mid].first < timestamp) {
                possibleIndex = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return possibleIndex == -1 ? "" : valueArr[possibleIndex].second;
    }
};
