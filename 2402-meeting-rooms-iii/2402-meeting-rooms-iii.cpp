class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(), meetings.end());

        // Available rooms -> smallest room number first
        priority_queue<int, vector<int>, greater<int>> free;

        // Taken rooms -> {endTime, roomNumber}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > taken;

        // Initially all rooms are free
        for(int i = 0; i < n; i++){
            free.push(i);
        }

        vector<int> ans(n, 0);

        for(int i = 0; i < meetings.size(); i++){
            
            long long starttime = meetings[i][0];
            long long endtime = meetings[i][1];

            // Free all rooms whose meetings have ended
            while(!taken.empty() && starttime >= taken.top().first){
                free.push(taken.top().second);
                taken.pop();
            }

            // If a room is available
            if(!free.empty()){
                
                int curr = free.top();
                free.pop();

                ans[curr]++;

                taken.push({endtime, curr});
            }

            // No room is available
            else {
                
                long long duration = endtime - starttime;

                // Earliest available room
                long long newEndTime = taken.top().first + duration;

                int curr = taken.top().second;
                taken.pop();

                ans[curr]++;

                taken.push({newEndTime, curr});
            }
        }

        // Find room with maximum meetings
        int mx = 0;
        int room = 0;

        for(int i = 0; i < n; i++){
            if(ans[i] > mx){
                mx = ans[i];
                room = i;
            }
        }

        return room;
    }
};