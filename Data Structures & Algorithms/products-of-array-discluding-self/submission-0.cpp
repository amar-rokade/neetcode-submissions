class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>ans(size);
        vector<int> lProd(size,1);
        vector<int> rProd(size,1);

        for(int i= 1; i< size; i++) lProd[i] = lProd[i-1] * nums[i-1];

        for(int i= size-2; i>=0; i--) rProd[i] = rProd[i+1] * nums[i+1];

        for(int i=0; i < size; i++) ans[i] = lProd[i]* rProd[i];

        return ans;
    }
};
