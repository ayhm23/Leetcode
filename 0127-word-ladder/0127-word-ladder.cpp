class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return 0;

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};

        dict.erase(beginWord);
        dict.erase(endWord);

        int level = 1;

        while (!beginSet.empty() && !endSet.empty()) {

            // Always expand the smaller frontier
            if (beginSet.size() > endSet.size())
                swap(beginSet, endSet);

            unordered_set<string> next;

            for (const string &word : beginSet) {

                string curr = word;

                for (int i = 0; i < curr.size(); i++) {

                    char original = curr[i];

                    for (char c = 'a'; c <= 'z'; c++) {

                        if (c == original)
                            continue;

                        curr[i] = c;

                        if (endSet.count(curr))
                            return level + 1;

                        if (dict.count(curr)) {
                            next.insert(curr);
                            dict.erase(curr);
                        }
                    }

                    curr[i] = original;
                }
            }

            beginSet = next;
            level++;
        }

        return 0;
    }
};