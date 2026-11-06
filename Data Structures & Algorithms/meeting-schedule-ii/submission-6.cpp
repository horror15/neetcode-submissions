/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){return a.start<b.start;});
        priority_queue<int, vector<int>, greater<int>>pq;
        pq.push(intervals[0].end);
        int room = 1;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].start >= pq.top()){
                pq.pop();
                pq.push(intervals[i].end);
            } else {
                room++;
                pq.push(intervals[i].end);
            }
        }
        return room;

    }
};
