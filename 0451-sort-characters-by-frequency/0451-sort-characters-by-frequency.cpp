#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<int> freq(128, 0); // ASCII chars frequency
        for(char c : s) freq[c]++;

        // strfreq[i] holds characters that appear i times
        vector<string> strfreq(n + 1);
        for(int c = 0; c < 128; ++c) {
            if(freq[c] > 0)
                strfreq[freq[c]].push_back((char)c);
        }

        stringstream ss;
        for(int i = n; i > 0; --i) {
            for(char c : strfreq[i]) {
                ss << string(i, c);
            }
        }
        return ss.str();
    }
};