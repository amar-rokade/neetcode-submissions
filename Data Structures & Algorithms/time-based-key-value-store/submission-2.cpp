class TimeMap {
    unordered_map<string, vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
    auto it = mp.find(key); 
    
    if (it != mp.end()) {
        const auto& v = it->second; 
        int s = 0; 
        int e = v.size() - 1;
        string prev = "";
        
        while(s <= e){
            int m = s + (e - s)/2;
            if(v[m].first == timestamp) return v[m].second;
            else if(v[m].first < timestamp){
                prev = v[m].second;
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return prev;
    }
    return "";
}
};
