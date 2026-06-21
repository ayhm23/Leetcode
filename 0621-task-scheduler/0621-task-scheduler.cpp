class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(int i = 0; i < tasks.size(); i++){
            freq[tasks[i] - 'A']++;
        }

        priority_queue<int> maxH;
        for (int f : freq) {
            if (f > 0)
                maxH.push(f);
        }
        queue<pair<int, int>> coolDown; //{remaining freq, cooldown time}

        //allot cpu to max avaliable freq
        int time = 0;
        while (!maxH.empty() || !coolDown.empty()) {
            time++;

            // bring back cooled tasks
            while (!coolDown.empty() && coolDown.front().second <= time) {
                maxH.push(coolDown.front().first);
                coolDown.pop();
            }

            if (!maxH.empty()) {
                int curr = maxH.top();
                maxH.pop();

                curr--;

                if (curr > 0)
                    coolDown.push({curr, time + n + 1});
            }
        }
        return time;
    }
};