class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>valToIndx;
        for(int i=0; i<nums.size();i++){
            int complementary = target - nums[i];
            if(valToIndx.find(complementary)!= valToIndx.end()){
                int j = valToIndx[complementary];
                return {j,i};
            }
            valToIndx[nums[i]] = i;
        }
        return {};
    }
};
