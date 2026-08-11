class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int, int> freq;

        for(auto& x : hand) freq[x]++;

        while(!freq.empty()){
            auto it = freq.begin();
            int num = it->first;
            if(!freq.count(num-1)){
                //we got the starting number
                for(int j = num; j < groupSize + num; j++){
                    if(freq.find(j) == freq.end()) return false;
                    else{
                        if(--freq[j] == 0) freq.erase(j);
                    }
                }
            }
        }
        return true;
    }
};