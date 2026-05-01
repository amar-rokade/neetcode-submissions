#include <string>
#include <iostream>

class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(string s:strs){
            int len = s.length();
            ans+= to_string(len) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int n = s.length();
        int i=0;
        vector<string>ans;
        while(i< n){
            string temp="";
            string lenS="";
            while(s[i]!= '#'){
                lenS+=s[i];
                i++;
            }
            i++;
            int lenI = stoi(lenS);
            while(lenI > 0){
                temp+=s[i];
                i++;
                lenI--;
            }
            ans.push_back(temp);
        }
        return ans;

    }
};
