class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequencies
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Put into max heap (priority_queue)
        priority_queue<pair<int, char>> pq;
        for (auto &p : freq) {
            pq.push({p.second, p.first});  // {frequency, char}
        }

        // Step 3: Build result string
        string result;
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            result.append(count, ch); // append 'ch' count times
        }

        return result;
    }
};
