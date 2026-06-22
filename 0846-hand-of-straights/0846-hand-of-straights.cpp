class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : hand)
            mp[x]++;

        for (auto &[num, cnt] : mp)
            pq.push(num);

        while (!pq.empty()) {
            int start = pq.top();

            for (int card = start; card < start + groupSize; card++) {

                if (mp[card] == 0)
                    return false;

                mp[card]--;

                if (mp[card] == 0) {
                    if (card != pq.top())
                        return false;

                    pq.pop();
                }
            }
        }

        return true;
    }
};