class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";

        auto &v = mp[key];

        int l = 0, r = v.size() - 1;
        string ans = "";

        while(l <= r){
            int mid = l + (r-l)/2;

            if(v[mid].first <= timestamp){
                ans = v[mid].second; // possible answer
                l = mid + 1;         // look for bigger timestamp
            }
            else{
                r = mid - 1;
            }
        }

        return ans;
    }
};