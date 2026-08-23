// My Code
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int totalCapacity){
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        int i = 0, j = 0, n = buses.size(), m = passengers.size(), currentCapacity;
        while(i < n){
            currentCapacity = 0;
            while(j < m && currentCapacity < totalCapacity && passengers[j] <= buses[i]){
                j++;
                currentCapacity++;
            }
            
			// Last Bus
            if(i == n - 1){
                j--;
                // If last bus has some seats left, then reach station at last bus departure time.
                if(currentCapacity < totalCapacity){
                    int time = buses[i];
                    while(j >= 0 && time == passengers[j]){ // if time clashes with other passenger, reach 1 minute early
                        time--, j--;
                    }
                    return time;
                }else{
                    // If bus is full, then we have to reach before the last person which is on board
                    int time = passengers[j] - 1;
                    j--;
                    while(j >= 0 && time == passengers[j]){  // if time clashes with other passenger, reach 1 minute early
                        time--, j--;
                    }
                    return time;
                }
            }
            i++;
        }
        return buses.back(); // just compiler thing
    }
};