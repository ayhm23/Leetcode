class Solution {
public:
    bool check(string word, int l, int r){
        set<char> st;
        for(int i = l; i <= r; i++){
            if(!(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')){
                return false;
            }
            st.insert(word[i]);
        }
        return st.size() == 5;
    }
    int countVowelSubstrings(string word) {
        int n = word.length();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(check(word, i, j)) cnt++;
            }
        }
        return cnt;
    }
};