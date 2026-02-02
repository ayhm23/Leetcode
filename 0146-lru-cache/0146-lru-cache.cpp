class LRUCache {
public:
    int cap;
    list<pair<int,int>> dll;  
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        // move accessed node to front (MRU)
        auto curr = mp[key];
        int value = curr->second;

        dll.erase(curr);
        dll.push_front({key, value});
        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {
        // key already exists
        if(mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        // cache full
        else if(dll.size() == cap) {
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }

        // insert new node at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};
