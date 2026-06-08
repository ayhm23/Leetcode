class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;
        while(iss >> word){
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        word = "";
        for(int i = 0; i < words.size(); i++){
            word += words[i]; 
            if(i + 1 != words.size()) word += " ";
        }
        return word;
    }
};