class LFUCache {
public:
    int cap, minFreq;

    unordered_map<int, list<pair<int,int>>> freqList; 
    unordered_map<int, pair<int, list<pair<int,int>>::iterator>> keyNode;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if(cap == 0 || keyNode.find(key) == keyNode.end())
            return -1;

        auto [freq, it] = keyNode[key];
        int value = it->second;

        // remove from old frequency list
        freqList[freq].erase(it);
        if(freqList[freq].empty()) {
            freqList.erase(freq);
            if(minFreq == freq) minFreq++;
        }

        // add to new frequency list
        freq++;
        freqList[freq].push_front({key, value});
        keyNode[key] = {freq, freqList[freq].begin()};

        return value;
    }

    void put(int key, int value) {
        if(cap == 0) return;

        if(keyNode.find(key) != keyNode.end()) {
            keyNode[key].second->second = value;
            get(key); // reuse logic
            return;
        }

        // eviction
        if(keyNode.size() == cap) {
            auto lru = freqList[minFreq].back();
            keyNode.erase(lru.first);
            freqList[minFreq].pop_back();
            if(freqList[minFreq].empty())
                freqList.erase(minFreq);
        }

        // insert new key
        freqList[1].push_front({key, value});
        keyNode[key] = {1, freqList[1].begin()};
        minFreq = 1;
    }
};
