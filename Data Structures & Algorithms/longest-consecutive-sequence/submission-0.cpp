class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> el;
        int n = nums.size();

        for( int i : nums) el.insert(i);

        int maxCount=0;

        for(int i=0; i< n; i++){
            if(el.count(nums[i]-1)){
                // present element
            }else{
                // not present then can be start of element
                int localCount=0;
                int localEl = nums[i];
                while(el.count(localEl)){
                    localCount++;
                    localEl++;
                }
                maxCount = max(localCount, maxCount);
            }
        }
        return maxCount;
    }
};
