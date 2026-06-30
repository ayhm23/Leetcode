class DisJointSet{
    private:
        unordered_map<string, string> UP_Name, parent;// CHANGED: parent should email -> parent email
        unordered_map<string, int> size;

    public:
        DisJointSet(){}

        string findP(string a){
            if(parent.find(a) == parent.end()){size[a] = 1;return parent[a] = a;}
            if(parent[a] == a) return a;
            return parent[a] = findP(parent[a]);
        }

        void unionBySize(string a, string b){
            string pa = findP(a), pb = findP(b);
            if(pa == pb) return;
            if(size[pa] >= size[pb]){
                parent[pb] = pa;
                size[pa] += size[pb];
            }
            else{
                parent[pa] = pb;
                size[pb] += size[pa];
            }
        }

        void setname(string s, string name){
            string p = findP(s);
            UP_Name[p] = name;
        }

        string getName(string s){
            return UP_Name[findP(s)];
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisJointSet dsu;
        for(auto &acc : accounts){
            for(int i = 1; i < acc.size()-1; i++){
                dsu.unionBySize(acc[i], acc[i+1]);
            }
        }

        // CHANGED: assign names AFTER all unions so final root gets the name
        for(auto &acc : accounts){
            dsu.setname(acc[1], acc[0]);
        }

        // CHANGED: group emails by ultimate parent
        unordered_map<string, vector<string>> groups;

        for(auto &acc : accounts){
            for(int i = 1; i < acc.size(); i++){
                groups[dsu.findP(acc[i])].push_back(acc[i]);
            }
        }

        vector<vector<string>> ans;

        for(auto &[root, emails] : groups){
            sort(emails.begin(), emails.end());

            // CHANGED: remove duplicate emails
            emails.erase(unique(emails.begin(), emails.end()), emails.end());

            vector<string> curr;
            curr.push_back(dsu.getName(root));

            for(auto &mail : emails)
                curr.push_back(mail);

            ans.push_back(curr);
        }

        return ans;
    }
};