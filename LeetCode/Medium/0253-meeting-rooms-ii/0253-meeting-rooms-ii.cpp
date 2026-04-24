class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;

        for (auto meeting : intervals) {
            start.push_back(meeting[0]);
            end.push_back(meeting[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0, ans = 0, room = 0;

        while (i < start.size()) {
            if (start[i] < end[j]) {
                room++;
                i++;
                ans = max(ans, room);
            } else {
                room--;
                j++;
            }
        }
        return ans;
    }
};