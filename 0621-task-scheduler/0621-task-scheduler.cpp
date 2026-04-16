class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();

        vector<int> freq(26, 0);
        
        for(char c : tasks){
            freq[c - 'A']++;
        }

        int maxF = *max_element(freq.begin(), freq.end());

        int count = 0;
        for(int f : freq){
            if(f == maxF) count++;
        }
        
        int calculated = (maxF - 1) * (n + 1) + count;
        
        // Step 5: Return the maximum of total tasks or calculated (in case no idle needed)
        return max((int)tasks.size(), calculated);
    }
};