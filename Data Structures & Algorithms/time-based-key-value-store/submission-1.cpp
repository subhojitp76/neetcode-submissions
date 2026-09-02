class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int lft = 0, rht = mp[key].size() - 1, mid;
        while(lft <= rht){
            mid = lft + (rht - lft) / 2;
            if(mp[key][mid].first == timestamp)
                return mp[key][mid].second;
            else if(mp[key][mid].first < timestamp)
                lft = mid + 1;
            else
                rht = mid - 1;
        }
        if(lft > 0)
            return mp[key][min(lft, rht)].second;
        return "";
    }
};
