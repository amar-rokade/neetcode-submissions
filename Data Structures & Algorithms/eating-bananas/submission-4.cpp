class Solution {
    int calculateHours(const vector<int>& piles, int k, int h) {
        int c = 0;
        // int instead of const auto avoids unnecessary const-casting under the hood for a simple primitive
        for (int pile : piles) { 
            c += (pile + k - 1) / k; // Branchless integer ceiling
            if (c > h) return -1;
        }
        return c;
    }

public:
    int minEatingSpeed(const vector<int>& piles, int h) {
        // Fast I/O trick to speed up LeetCode's behind-the-scenes test case loading
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int minK = 1;
        int maxK = 1000000000; // Skips the O(N) max_element scan based on problem constraints
        int ans = maxK;

        while (minK <= maxK) {
            int mid = minK + (maxK - minK) / 2;
            int requiredH = calculateHours(piles, mid, h);

            if (requiredH == -1) {
                minK = mid + 1;
            } else {
                ans = mid;
                maxK = mid - 1;
            }
        }
        return ans;
    }
};