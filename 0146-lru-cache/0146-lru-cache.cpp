class LRUCache {
    list<pair<int,int>> lis;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.count(key) == 0) return -1;
        auto& it = mp[key];
        int val = it->second;
        lis.erase(it);
        lis.push_front({key, val});
        mp[key] = lis.begin();
        
        return val;
    }
    
    void put(int key, int value) {
        if(mp.count(key) != 0){
            auto it = mp[key];
            lis.erase(it);
        }

        lis.push_front({key, value});
        mp[key] = lis.begin(); 
        
        if(lis.size() > cap){
            auto it = lis.back();
            int key = it.first;
            lis.pop_back();
            mp.erase(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */