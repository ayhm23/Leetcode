class LRUCache {
public:
    list<pair<int,int>> dll; 
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    void makeRecentlyUsed(int key, int value) {
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int val = it->second;

        dll.erase(it);
        mp.erase(key);

        makeRecentlyUsed(key, val);

        return val;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {
            auto it = mp[key];
            dll.erase(it);
            mp.erase(key);
        }

        if(dll.size() == cap) {
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }

        makeRecentlyUsed(key, value);
    }
};