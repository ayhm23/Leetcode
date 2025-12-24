class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";

        while (!pq.empty()) {
            auto it = pq.top(); 
            pq.pop();

            int freq = it.first;
            char c = it.second;

            while (freq--) {
                ans += c;
            }
        }
        return ans;
    }
};
