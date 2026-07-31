class TrieNode{
public:
    TrieNode* children[26];
    int idx;
    int refs;

    TrieNode(){
        for(int i=0;i<26;i++)
            children[i]=nullptr;
        idx=-1;
        refs=0;
    }

    void addword(string word,int id){
        TrieNode* cur=this;

        for(char c:word){
            int i=c-'a';

            if(!cur->children[i])
                cur->children[i]=new TrieNode();

            cur=cur->children[i];
            cur->refs++;
        }

        cur->idx=id;
    }
};


class Solution {

    vector<string> ans;
    int r,c;

    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};

public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){

        TrieNode* root=new TrieNode();

        for(int i=0;i<words.size();i++)
            root->addword(words[i],i);


        r=board.size();
        c=board[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                dfs(board,words,i,j,root);
            }
        }

        return ans;
    }


    void dfs(vector<vector<char>>& board,
             vector<string>& words,
             int x,int y,
             TrieNode* node){

        if(x<0 || x>=r || y<0 || y>=c)
            return;


        char ch=board[x][y];

        if(ch=='*' || node->children[ch-'a']==nullptr)
            return;


        TrieNode* next=node->children[ch-'a'];

        board[x][y]='*';


        if(next->idx!=-1){

            ans.push_back(words[next->idx]);

            next->idx=-1;
        }


        for(int k=0;k<4;k++){
            dfs(board,
                words,
                x+dx[k],
                y+dy[k],
                next);
        }


        board[x][y]=ch;
    }
};