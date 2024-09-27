class MyCalendarTwo {
public:
    vector<pair<int,int>> bookings;
    vector<pair<int,int>> overlaps;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(const auto& [s,e]:overlaps){
            if(max(s,start)<min(end,e)){
                return false;
            }   
        }
          for (const auto& [s, e] : overlaps) {
            if (max(s, start) < min(e, end)) {
                return false;  
            }
        }

        for(const auto& [s,e]:bookings){
            int startTime = max(s,start);
            int endTime = min(e,end);

            if(startTime<endTime){
                overlaps.push_back({startTime,endTime});
            }
        }

        bookings.push_back({start,end});
        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */