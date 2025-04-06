class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (words.find(endWord) == words.end()) return {};

        unordered_map<string, int> levels;
        unordered_map<string, vector<string>> parents;
        queue<string> q;

        q.push(beginWord);
        levels[beginWord] = 1;
        words.erase(beginWord);

        while (!q.empty()) {
            int levelSize = q.size();
            unordered_set<string> visitedThisLevel;

            for (int i = 0; i < levelSize; ++i) {
                string word = q.front(); q.pop();
                int currLevel = levels[word];

                for (int j = 0; j < word.size(); ++j) {
                    string nextWord = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        if (nextWord == word) continue;

                        if (levels.find(nextWord) == levels.end() && words.find(nextWord) != words.end()) {
                            // First time visit
                            levels[nextWord] = currLevel + 1;
                            q.push(nextWord);
                            visitedThisLevel.insert(nextWord);
                            parents[nextWord].push_back(word);
                        } else if (levels[nextWord] == currLevel + 1) {
                            // Already visited on same level → valid parent
                            parents[nextWord].push_back(word);
                        }
                    }
                }
            }

            for (const string& w : visitedThisLevel) {
                words.erase(w);
            }
        }

        if (levels.find(endWord) == levels.end()) return {}; // No path

        vector<string> path;
        backtrack(endWord, beginWord, parents, path, result);
        return result;
    }

private:
    void backtrack(string word, string beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path,
                   vector<vector<string>>& result) {
        if (word == beginWord) {
            path.push_back(word);
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            result.push_back(validPath);
            path.pop_back();
            return;
        }

        path.push_back(word);
        for (const string& p : parents[word]) {
            backtrack(p, beginWord, parents, path, result);
        }
        path.pop_back();
    }
};
