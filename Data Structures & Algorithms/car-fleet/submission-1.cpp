class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> car;
        for(int i = 0; i < position.size(); i++) {
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end());

        stack<float> st;
        int n = car.size();
        for(int i = n-1; i >= 0; i--) {
            float time = ((target - car[i].first)*1.0) / car[i].second;
            if (st.empty()) st.push(time);
            else {
                if (time > st.top()) {
                    st.push(time);
                }
            }
        }
        return st.size();
    }
};