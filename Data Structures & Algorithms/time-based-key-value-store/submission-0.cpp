class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
        // cout << " hello";
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = mp[key].size()-1, mid;
        // cout << l << " " << r << endl;
        while(l <= r){
            mid = (r + l) / 2;
            if(mp[key][mid].first == timestamp)
                return mp[key][mid].second;
            if(mp[key][mid].first < timestamp)
                l = mid + 1;
            else
                r = mid - 1;
        }
        // cout << l << " " << r << endl;
        if(l > 0)
            return mp[key][min(l, r)].second;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */