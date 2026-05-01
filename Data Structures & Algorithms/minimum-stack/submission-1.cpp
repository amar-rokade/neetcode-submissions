class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()||minSt.top() >= val) minSt.push(val);        
    }
    
    void pop() {
        int top = st.top();
        st.pop();
        if(minSt.top() == top)minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
