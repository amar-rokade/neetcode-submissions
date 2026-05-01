class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int profit= 0;
        int minValue = INT_MAX;

        for(int i=0; i<n ; i++){
            minValue = min(minValue, prices[i]);
            profit = max(profit, prices[i]-minValue);
        }

        return profit;

    }
};
// 10 1 5 6 7 1
// 
// 
// 