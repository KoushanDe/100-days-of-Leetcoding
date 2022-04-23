#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    map<string,string> longtoshort;
    long long id = 0;
    long long temp;
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        temp = id;
        string shorturl;
        while(temp>0)
        {
            shorturl.push_back(characters[temp%62]);
            temp/=62;
        }
        while(shorturl.size()<6)
        {
            shorturl.push_back(characters[0]);
        }
        reverse(shorturl.begin(),shorturl.end());
        id++;
        longtoshort[shorturl] = longUrl;
        return shorturl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return longtoshort[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));