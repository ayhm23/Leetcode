class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        
        // Count frequencies
        for (char c : s) {
            mp[c]++;
        }
        
        // Max heap by frequency
        priority_queue<pair<int, char>> pq;
        for (auto &it : mp) {
            pq.push({it.second, it.first});
        }
        
        string result;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            result.append(it.first, it.second); // repeat char 'it.second', it.first times
        }
        
        return result;
    }
};
