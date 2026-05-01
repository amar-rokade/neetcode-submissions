class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()) minSt.push(val);
        else if (minSt.top() >= val) minSt.push(val);        
    }
    
    void pop() {
        int top = st.top();
        st.pop();
        if(!minSt.empty() and minSt.top() == top)minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
