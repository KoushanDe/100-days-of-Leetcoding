class MyCalendar {
public:
    set<pair<int,int>> time;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto p:time)
        {
            if((p.first<=start&&p.second>=start)||(p.first<=end-1&&p.second>=end-1)||(p.first>=start&&p.second<=end-1))
                return false;
        }
        time.insert({start,end-1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */