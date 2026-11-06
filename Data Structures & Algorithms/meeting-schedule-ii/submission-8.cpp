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
        sort(intervals.begin(), intervals.end(), [](auto&a, auto&b){return a.start<b.start;});
        if(intervals.size()==0) return 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        pq.push(intervals[0].end);
        int i=1, count=1;
        while(i<intervals.size()){
            if(intervals[i].start>=pq.top()){
                pq.pop();
            }
            pq.push(intervals[i].end);
            int sz = pq.size();
            count = max(count, sz);
            i++;
        }
        return count;
    }
};
