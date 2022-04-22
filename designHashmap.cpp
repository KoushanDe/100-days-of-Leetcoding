#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class MyHashMap {
public:
    int temp[1000001];
    int* hashmap;
    MyHashMap() {
        hashmap = temp; 
        for(int i=0;i<1000001;i++)
            hashmap[i]=-1;
    }
    
    void put(int key, int value) {
        hashmap[key] = value;
    }
    
    int get(int key) {
        return hashmap[key];
    }
    
    void remove(int key) {
        hashmap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */