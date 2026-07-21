class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        
        for(int i = 0; i < n; i++){
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort cars by their starting position in descending order 
        // (cars closest to the target come first)
        sort(cars.rbegin(), cars.rend());

        stack<double> st;

        for(int i = 0; i < n; i++){
            double currentTime = cars[i].second;
            
            // If the current car takes longer than the car ahead of it, 
            // it cannot catch up and forms a new fleet.
            if(st.empty() || currentTime > st.top()){
                st.push(currentTime);
            }
            // Otherwise, it catches up and merges into the fleet ahead (do nothing).
        }

        return st.size();
    }
};