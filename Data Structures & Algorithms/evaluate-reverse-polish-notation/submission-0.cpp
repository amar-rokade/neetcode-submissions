class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> opt = {"+", "-", "*","/"};
        stack<int> st;
        for(auto token: tokens){
            if(opt.count(token)){
                int second = st.top();
                st.pop();
                int first = st.top();
                st. pop();
                int result; 
                if (token == "+") {
                    result = first +  second ;
                } else if (token == "-") {
                    result = first -  second ;
                } else if (token == "*") {
                    result = first * second ;
                } else if (token == "/") {
                    result =(int) first /  second ;
                }
                st.push(result);

            }else{
                st.push((stoi(token)));
            }
        }
        return st.top();
        
    }
};
