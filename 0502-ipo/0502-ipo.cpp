#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Min-heap for capital requirements (capital, index)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minCap;
        for(int i = 0; i < n; i++) {
            minCap.push({capital[i], i});
        }
        
        // Max-heap for profits of affordable projects
        priority_queue<int> maxProfit;
        
        int currCapital = w;
        
        for(int i = 0; i < k; i++) {
            // Push all projects affordable with current capital to maxProfit heap
            while(!minCap.empty() && minCap.top().first <= currCapital) {
                int idx = minCap.top().second;
                minCap.pop();
                maxProfit.push(profits[idx]);
            }
            
            if(maxProfit.empty()) {
                // No projects can be done
                break;
            }
            
            // Pick project with max profit
            currCapital += maxProfit.top();
            maxProfit.pop();
        }
        
        return currCapital;
    }
};
