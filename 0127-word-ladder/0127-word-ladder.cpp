class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(auto it : wordList){
            words.insert(it);
        }
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);

        if (words.find(endWord) == words.end()) return 0;


        while(!q.empty()){
            auto it = q.front();
            q.pop();

            string currWord = it.first;
            int currLevel = it.second;
            
            for(int i = 0; i < currWord.length(); i++){
                for(int j = 0; j < 26; j++){
                    string nextWord = currWord.substr(0, i) + char('a' + j) + currWord.substr(i + 1);
                    int nextLevel = currLevel + 1;

                    if(nextWord == endWord){
                        return nextLevel;
                    }

                    if(words.find(nextWord) != words.end()){
                        q.push({nextWord, nextLevel});
                        words.erase(nextWord);
                    }
                }
            }
        }
        return 0;
    }
};