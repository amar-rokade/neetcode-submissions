class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n = temperatures.size();
    vector<int> result(n, 0); 
    stack<int> st; 

    for (int i = 0; i < n; i++) {
        // The Trigger: A warmer day arrives
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int past_index = st.top(); 
            st.pop(); 
            result[past_index] = i - past_index; // Calculate the wait time
        }
        
        // Step 4: The current day always joins the waitlist
        st.push(i);
    }
    return result;
        
    }
};
