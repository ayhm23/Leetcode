class LRUCache {
public:
    int n;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int, int>> lst;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        auto it = mp[key];
        lst.push_front({it->first, it->second});
        int ans = it->second;
        lst.erase(it);
        mp.erase(key);
        mp[key] = lst.begin();
        return ans;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){ //key exists
            auto it = mp[key];
            mp.erase(key);
            lst.erase(it);
        }
        else if(lst.size() == n){ //key exists
            auto it = prev(lst.end());
            
            mp.erase(it->first);
            lst.erase(it);
        }

        lst.push_front({key, value});
        mp[key] = lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */