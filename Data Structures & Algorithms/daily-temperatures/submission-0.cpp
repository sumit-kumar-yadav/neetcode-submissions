class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();

        vector<int> output(n);
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) st.pop();
            output[i] = !st.empty() ? st.top() - i : 0;
            st.push(i);
        }
        return output;
    }
};