class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        vector<vector<int>> ans;

        for(int i=0; i< n-2; i++){
            if(i> 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j < k){

                long long sum = nums[i] + nums[j] + nums[k];

                if( sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int lastj = nums[j];
                    int lastk = nums[k];

                    while(j< k && nums[j] == lastj)j++;
                    while(k > j && nums[k] == lastk) k--;
                }
                else if( sum < 0)j++;
                else k--;
            }
        }
        return ans;
    }
};
