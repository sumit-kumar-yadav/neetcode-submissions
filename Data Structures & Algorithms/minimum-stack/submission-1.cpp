class MinStack {
public:
    stack<int> st;
    priority_queue<int, vector<int>, greater<int>> minPq;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        minPq.push(val);
    }
    
    void pop() {
        int el = st.top();
        st.pop();

        bool removed = false;

        priority_queue<int, vector<int>, greater<int>> temp;

        while(!minPq.empty()) {

            if(minPq.top() == el && !removed) {
                removed = true;   // skip only first match
            }
            else {
                temp.push(minPq.top());
            }

            minPq.pop();
        }

        minPq = temp;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minPq.top();
    }
};
