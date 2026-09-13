class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            // max-heap by distance → farthest on top
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        for (const auto& point : points) {
            pq.push(point);
            if ((int)pq.size() > k) {
                pq.pop();   // evict farthest
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};