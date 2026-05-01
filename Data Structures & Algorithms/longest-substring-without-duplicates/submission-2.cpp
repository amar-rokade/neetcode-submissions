class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==1)return 1;
        int global_max = 0;
        set<int> char_set;
        int start=0 ,  e=0; 
        while(start < n && e < n){
            if(char_set.find(s[e]) != char_set.end()){
                global_max = max(global_max, e-start);

                while(char_set.find(s[e]) != char_set.end()){
                    
                    char_set.erase(s[start]);
                    start++;
                }
                char_set.insert(s[e]);
                e++;
            }else{
                char_set.insert(s[e]);
                e++;
            }
        }
        global_max = max(global_max, e-start);

        return global_max;
    }
};
