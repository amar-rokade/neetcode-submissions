class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        string ans=strs[0];

        for(int i=1; i <strs.size();i++){
            string localPrefix="";
            for(int j=0; j<ans.length(); j++){
                if(ans[j]!= strs[i][j]) break;
                localPrefix+=ans[j];
            }

            if(localPrefix.length() == 0) return "";
            ans = localPrefix;
        }
        return ans;
    }
};