class Solution {
    int calculateHours(vector<int>& piles, int k, int h){
        int c = 0;
        for(const auto pile: piles){
           c+= (pile / k) + (pile % k != 0 ? 1 : 0);
        //    no pint in calculating higher 
           if(c > h) return -1;
        }

        return c;

    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int minK=1;
        int maxK = *max_element(piles.begin(), piles.end());
        int ans =INT_MAX;

        while(minK <= maxK){
            int mid = minK + (maxK -minK)/2;

            int requiredH = calculateHours(piles, mid,h);

            if(requiredH == -1){
                // its going above limit so not valid rate so we needs to increase our rate of eating 
                minK = mid+1;
            }else {
                // completing in required time so check if more lower rate possible or not 
                ans = min(ans, mid);
                maxK = mid-1;
            }

        }
        return ans;
    }
};
