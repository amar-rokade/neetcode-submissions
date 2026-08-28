class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int area = 0;
        for(int i=0;i<n;i++){
            if(st.size() == 0){
                st.push(i);
            }else if(heights[st.top()]<=heights[i]){
                st.push(i);
            }else{
               
                while(st.size()!=0 && heights[st.top()]> heights[i]){
                    int cuHgt = heights[st.top()];
                    st.pop();
                    int lf = st.size()==0 ? -1 : st.top();
                    int temp = cuHgt * (i - lf-1);
                    area = max(temp, area);                    //calculate
                }
               
                st.push(i);
            }
        }


        while(st.size()!=0){
            int crHgt= heights[st.top()];
            st.pop();
            int lf= st.size()==0 ? -1 : st.top();
            int temp = crHgt * (n-lf-1);
            area = max(area, temp);
        }

        return area;
    }
};
