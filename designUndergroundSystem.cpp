#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class UndergroundSystem {
public:
    map<string,pair<double,int>> tottime;
    map<int,pair<string,int>> stationcheck;
    UndergroundSystem() {
        tottime.clear();
        stationcheck.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        stationcheck[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string start = stationcheck[id].first;
        int stime = stationcheck[id].second;
        tottime[start+"-"+stationName].first += (t-stime);
        tottime[start+"-"+stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (tottime[startStation+"-"+endStation].first/tottime[startStation+"-"+endStation].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */