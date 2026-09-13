class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(auto el:stones)maxHeap.push(el);

        while(maxHeap.size()>1){
            int el1 = maxHeap.top();
            maxHeap.pop();
            int el2 = maxHeap.top();
            maxHeap.pop();

            if(el1- el2 != 0) {
                maxHeap.push(abs(el1-el2));
            }
        }

        return maxHeap.size() == 0 ? 0 : maxHeap.top();
    }
};
