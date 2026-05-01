class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> closing = {{')', '('}, {']', '['}, {'}', '{'}};
        for(auto c : s){
            if(closing.count(c)){
                if(st.empty()|| st.top() != closing[c]) return false;
                st.pop();
            }
            else st.push(c);
        }
        return st.empty();
    }
};
