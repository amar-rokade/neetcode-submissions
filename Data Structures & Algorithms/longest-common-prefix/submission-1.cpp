class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        string prefix=strs[0];

        for(int i=1; i <strs.size();i++){
            int commonLen = 0;
            int len = min(prefix.length(), strs[i].length());
            for(int j=0; j<=len; j++){
                if(prefix[j]!= strs[i][j]) break;
                commonLen++;
            }

            prefix = prefix.substr(0, commonLen);
            if (prefix.empty()) return prefix;
        }
        return prefix;
    }
};