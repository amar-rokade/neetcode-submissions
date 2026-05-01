class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int global_max= 0; 
        vector<int> last_indx(128, -1);
        int start=0;
        for(int end=0; end <s.length(); end++){
            char cur = s[end];

            if(last_indx[cur] !=-1){
                //  present then update start to next start 
                start = max(start, last_indx[cur]+1);
            }

            last_indx[cur] = end;
            global_max = max(global_max, end-start+1);
        }
        return global_max;
    }
};
