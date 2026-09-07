class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        //sort by end time;

        sort(rides.begin(), rides.end(), [&](auto& a, auto& b){
            if(a[1] >= b[1]) return false;
            else return true;
        });
        vector<int> ends;
        for(auto& it : rides){
            ends.push_back(it[1]);
        }

        using ll = long long;
        vector<ll> dp(n+1, 0LL); //dp[i] = till distance i whats best profit;
        int j = 0, m = rides.size();
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1];

            while(j < m && rides[j][1] == i){
                ll rideProfit = rides[j][1] - rides[j][0] + rides[j][2];
                ll lastP = dp[rides[j][0]];
                dp[i] = max(dp[i], rideProfit + lastP);
                j++;
            }
        }
        return dp[n];
    }
};