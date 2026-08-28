class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;
        
        for(int i = 0; i < n; i++) {
            // Trigger the pop and calculate INSIDE the while loop
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int currHeight = heights[st.top()];
                st.pop();
                
                // Now that it's popped, find the left edge
                int leftEdge = st.empty() ? -1 : st.top();
                int rightEdge = i; // The current index is the right edge
                
                int width = rightEdge - leftEdge - 1;
                maxArea = max(maxArea, currHeight * width);
            }
            // Always push the current index after clearing out taller bars
            st.push(i);
        }

        // Handle the leftovers
        int rightEdgeLeftover = n; // Use 'n', not 'n-1'
        
        while(!st.empty()) {
            int currHeight = heights[st.top()];
            st.pop();
            
            int leftEdge = st.empty() ? -1 : st.top();
            
            int width = rightEdgeLeftover - leftEdge - 1;
            maxArea = max(maxArea, currHeight * width);
        }

        return maxArea;
    }
};
