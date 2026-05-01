class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,int> sortStrVsindxMp;
        for(string str:strs){
            string originalSt = str;
            sort(str.begin(), str.end());
            if(sortStrVsindxMp.find(str) !=sortStrVsindxMp.end()){
                int indx = sortStrVsindxMp[str];
                ans[indx].push_back(originalSt);
            }else{
                ans.push_back({originalSt});
                sortStrVsindxMp[str] =ans.size()-1 ;
            }
        }
        return ans;
    }
};
