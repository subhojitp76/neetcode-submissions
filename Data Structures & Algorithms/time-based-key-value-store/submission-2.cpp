class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = mp[key].size() - 1, mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(mp[key][mid].first == timestamp)
                return mp[key][mid].second;
            else if(mp[key][mid].first > timestamp)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if(l > 0)
            return mp[key][min(l, r)].second;
        return "";
    }
};
