class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        unordered_map<int,int>umap;

        for(int x:nums) umap[x]++;

        for(auto& p: umap){
            minHeap.push({p.second,p.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int>result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;

    }
};
