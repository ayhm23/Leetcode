class Solution {
public:
    vector<int> dp;

    bool exist(string &s, vector<string> &wordDict, int i) {
        if (i == s.length())
            return true;

        if (dp[i] != -1)
            return dp[i];

        for (int j = 0; j < wordDict.size(); j++) {
            string &word = wordDict[j];

            if (s.substr(i, word.length()) == word) {
                if (exist(s, wordDict, i + word.length()))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size(), -1);
        return exist(s, wordDict, 0);
    }
};