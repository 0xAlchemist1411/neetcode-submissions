class MinStack {
public:
    MinStack() {}
    
    stack<int> stk;

    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        int minL = INT_MAX;
        stack<int> st(stk);

        while(!st.empty()){
            int top = st.top();
            st.pop();
            minL = min(minL,top);
        }
        
        return minL;
    }
};









