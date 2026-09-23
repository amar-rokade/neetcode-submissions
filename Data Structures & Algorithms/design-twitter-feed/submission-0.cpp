class Twitter {
private:
    int count;  // global timestamp, increments on every post

    // tmap[userId] = list of {timestamp, tweetId}, ascending by timestamp
    unordered_map<int, vector<pair<int,int>>> tmap;

    // fmap[userId] = set of users that userId follows
    unordered_map<int, unordered_set<int>> fmap;

public:
    Twitter() {
        count = 0;
    }

    void postTweet(int userId, int tweetId) {
        tmap[userId].push_back({count++, tweetId});
        // optional memory trim: only keep the 10 newest
        if (tmap[userId].size() > 10) {
            tmap[userId].erase(tmap[userId].begin());
        }
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        // max-heap by timestamp.
        // entry: {timestamp, tweetId, followeeId, indexInThatUsersList}
        auto cmp = [](const array<int,4>& a, const array<int,4>& b) {
            return a[0] < b[0];   // largest timestamp = top
        };
        priority_queue<array<int,4>, vector<array<int,4>>, decltype(cmp)> maxHeap(cmp);

        // candidates = self + everyone they follow
        // (insert self into fmap so it's naturally included)
        fmap[userId].insert(userId);

        for (int followeeId : fmap[userId]) {
            auto it = tmap.find(followeeId);
            if (it != tmap.end() && !it->second.empty()) {
                int idx = (int)it->second.size() - 1;   // latest tweet
                auto& t = it->second[idx];
                maxHeap.push({t.first, t.second, followeeId, idx});
            }
        }

        // pop newest, then refill that user's previous tweet
        while (!maxHeap.empty() && (int)res.size() < 10) {
            auto curr = maxHeap.top();
            maxHeap.pop();

            res.push_back(curr[1]);   // tweetId

            int followeeId = curr[2];
            int idx = curr[3];
            if (idx > 0) {
                auto& prev = tmap[followeeId][idx - 1];
                maxHeap.push({prev.first, prev.second, followeeId, idx - 1});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        fmap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        // don't erase self-follow (we only added it during getNewsFeed)
        if (followerId != followeeId) {
            fmap[followerId].erase(followeeId);
        }
    }
};