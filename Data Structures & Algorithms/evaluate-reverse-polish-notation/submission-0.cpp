class Solution {
public:
    int calculate(int op1, int op2, string op) {
        if(op == "+") return op1 + op2;
        else if(op == "-") return op1 - op2;
        else if(op == "*") return op1 * op2;
        else return op1 / op2;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                st.push(stoi(tokens[i]));
            } 
            else {
                int op2 = st.top();
                st.pop();
                
                int op1 = st.top();
                st.pop();

                st.push(calculate(op1, op2, tokens[i]));
            }
        }
        return st.top();
    }
};