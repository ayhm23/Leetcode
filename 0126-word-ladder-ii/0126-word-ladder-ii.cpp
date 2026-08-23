class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parents;
    unordered_map<string, int> dist;
    void dfs(string curr, string startWord, vector<string>& path){
        if(curr == startWord){
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        
        for(string parent : parents[curr]){
            path.push_back(parent);
            dfs(parent, startWord, path);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string startWord, string endWord, vector<string>& wordList) { 
        unordered_set<string> list (wordList.begin(), wordList.end());
        //the plan is to bfs to make the pasrents arraty then back track..bfs from start word
        if(!list.count(endWord)) return {};
        if(list.count(startWord)) list.erase(startWord); 

        queue<string> q; q.push(startWord);
        dist[startWord] = 1;

        while(!q.empty()){
            string curr = q.front(); q.pop();
            for(int i = 0; i < curr.length(); i++){
                string temp = curr;
                for(int j = 0; j < 26; j++){
                    temp[i] = 'a' + j;
                    if(temp == curr) continue;
                    if(!list.count(temp)) continue;

                    if(!dist.count(temp)){
                        dist[temp] = dist[curr] + 1;
                        parents[temp].push_back(curr);
                        q.push(temp);
                    }
                    //what if it alrteady exits
                    else if(dist[temp] == dist[curr]+1){
                        parents[temp].push_back(curr);
                    }
                }
            }
        }
        vector<string> res;
        res.push_back(endWord);
        dfs(endWord, startWord, res);
        return ans;
    }   
};