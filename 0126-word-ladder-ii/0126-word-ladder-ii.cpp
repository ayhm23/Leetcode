class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {}; // Early exit if endWord is not in wordList

        unordered_map<string, vector<string>> parents; // Store parent-child relationships
        unordered_set<string> currentLevel{beginWord}; // Current BFS level
        bool found = false;

        // BFS Traversal
        while (!currentLevel.empty() && !found) {
            unordered_set<string> nextLevel;
            for (const string& word : currentLevel) dict.erase(word); // Remove words used on this level
            
            for (const string& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < word.size(); i++) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        temp[i] = c;
                        if (dict.count(temp)) {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word); // Store the transformation path
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = original;
                }
            }
            currentLevel = move(nextLevel); // Move to the next level
        }

        // If no paths found, return empty result
        if (!found) return {};

        // Reconstruct paths using DFS
        vector<vector<string>> ans;
        vector<string> path = {endWord};
        dfs(ans, parents, path, endWord, beginWord);
        return ans;
    }

private:
    void dfs(vector<vector<string>>& ans, unordered_map<string, vector<string>>& parents, 
             vector<string>& path, const string& word, const string& beginWord) {
        if (word == beginWord) {
            ans.push_back(vector<string>(path.rbegin(), path.rend())); // Reverse path
            return;
        }
        for (const string& parent : parents[word]) {
            path.push_back(parent);
            dfs(ans, parents, path, parent, beginWord);
            path.pop_back();
        }
    }
};