class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int element : nums){
            if(seen.find(element) != seen.end()){
                return true;
            }
            seen.insert(element);

        }
        return false;
    }
};