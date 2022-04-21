#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class MyHashSet {
public:
    int hashset[1000001];
    MyHashSet() {
    }
    
    void add(int key) {
        hashset[key]=1;
    }
    
    void remove(int key) {
        hashset[key]=0;
    }
    
    bool contains(int key) {
        return hashset[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */