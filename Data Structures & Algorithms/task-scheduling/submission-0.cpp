class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count how many times each task appears
        unordered_map<char, int> counts;
        for (char t : tasks) counts[t]++;

        // Max-heap of remaining counts: always run the most-frequent ready task
        priority_queue<int> maxHeap;
        for (auto& [c, cnt] : counts) maxHeap.push(cnt);

        // FIFO queue of {remaining count, ready time}: tasks on cooldown,
        // ordered by when they free up (earliest at front)
        queue<pair<int,int>> cooldown;

        int time = 0;
        while (!maxHeap.empty() || !cooldown.empty()) {

            // Release the task whose cooldown expired; it becomes ready again.
            // Only the front matters: ready times are in increasing order.
            if (!cooldown.empty() && time >= cooldown.front().second) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }

            // Run the highest-count ready task (if any)
            if (!maxHeap.empty()) {
                int cnt = maxHeap.top() - 1;   // use one occurrence
                maxHeap.pop();
                if (cnt > 0)                   // still has copies → cooldown
                    cooldown.push({cnt, time + n + 1});
                // if cnt == 0, task is fully done, drop it
            }
            // else: heap empty → IDLE cycle (do nothing but advance time)

            time++;   // advance one CPU cycle either way
        }
        return time;
    }
};