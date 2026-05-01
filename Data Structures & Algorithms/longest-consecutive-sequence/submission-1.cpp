class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> el(nums.begin(), nums.end());  // Use constructor!
        int maxCount = 0;
        
        for(int num : el) {  // Iterate SET, not vector!
            if(el.count(num-1) == 0) {  // No previous = START
                int localCount = 1;
                int localEl = num + 1;
                while(el.count(localEl)) {
                    localCount++;
                    localEl++;
                }
                maxCount = max(localCount, maxCount);
            }
        }
        return maxCount;
    }
};
