class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;

        while (iss >> word)
            words.push_back(word);

        string ans;
        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            if (i) ans += " ";
        }

        return ans;
    }
};