class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;

        for(char task:tasks) mp[task]++;

        priority_queue<int> pq;

        // adding maxheap
        for(auto& [c, cnt] : mp)pq.push(cnt);

        queue<pair<int,int>> cp; //first is total count and second cooling time

        int time=0;

        while(!pq.empty()|| !cp.empty()){

            //move cooling to pd which can be taken;
            if(!cp.empty() && time>= cp.front().second){
                pq.push(cp.front().first); //we are pushing frequency left 
                cp.pop();
            }

            if(!pq.empty()){
                int count = pq.top()-1;
                pq.pop();
                if(count>0) cp.push({count, time+n+1});

            }

            time++;

        }
        return time;

    }
};