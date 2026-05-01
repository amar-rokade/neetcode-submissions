class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;

        int n = height.size();
        vector<int>lh(n,0);
        vector<int>rh(n,0);

        lh[0]=height[0];
        rh[n-1] = height[n-1];

        for(int i=1; i < n; i++) lh[i] = max(lh[i-1], height[i]);
        for(int i=n-2; i>=0; i--) rh[i] = max(rh[i+1], height[i]);

        for(int i=1; i<n-1; i++){
            ans+= abs(height[i] - min(rh[i], lh[i]));
        }

        return ans;
    }
};
