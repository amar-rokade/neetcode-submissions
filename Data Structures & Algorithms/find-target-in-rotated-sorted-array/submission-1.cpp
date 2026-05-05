class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = nums.size()-1;
        int pivot = -1;

        if(n==1){
            return (nums[0] == target) ? 0 :  -1;
        }

        if(nums[0] < nums[n-1]) pivot = 0;
        if(pivot  == -1){
            // it means array is not sorted  then find pivot using BS
            while(s < e){
            int mid = s + (e - s)/2;
            int pre = (mid-1+n)%n;
            // int next = (mid+1) % n; 
            if(nums[mid] < nums[pre]){
                pivot = mid;
                break;
            }
            else if(nums[mid] > nums[e]) s = mid+1;
            else e = mid-1;
            }

            if(pivot == -1) {
                pivot = s;
            }
        }

        if(target <= nums[n-1]){
            s = pivot;
            e = n-1;
        }else {
            s = 0;
            e = pivot-1;
        }

        while(s <= e){
            int mid = s + (e - s)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                s = mid+1;
            }
            else e = mid-1;
            }

            return -1;
        
    }
};
