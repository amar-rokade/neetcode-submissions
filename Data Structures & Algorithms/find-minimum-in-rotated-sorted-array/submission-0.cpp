class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int s = 0;
        int e = nums.size()-1;

        if(n==1 || nums[0] < nums[n-1]) return nums[0];

        while(s < e){
            int mid = s + (e - s)/2;
            int pre = (mid-1+n)%n;
            // int next = (mid+1) % n; 
            if(nums[mid] < nums[pre])return nums[mid];
            else if(nums[mid] > nums[e]) s = mid+1;
            else e = mid-1;
        }
    }
};
