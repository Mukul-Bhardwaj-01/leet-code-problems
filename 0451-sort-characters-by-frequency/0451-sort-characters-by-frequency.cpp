class Solution {
public:
    static bool comp(pair<char,int>& p1, pair<char,int>& p2) {
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        int n = s.length();
        vector<pair<char, int>> hashvec; //vector to store char and their freq from s
        for(char c : s) {
            auto it = find_if(hashvec.begin(),hashvec.end(),
            [c](const pair<char,int>& p) {return p.first == c;});
            if(it != hashvec.end()) {
                int indx = it - hashvec.begin();
                hashvec[indx].second++;
            }
            else hashvec.push_back({c,1});
        }
        vector<string> strfreq(n+1); //vector with ith index having char/s that appear i times
        for(auto it : hashvec) strfreq[it.second] += it.first;
        //traversing strfreq from back and adding char/s into result
        stringstream ss;
        for(int i = n; i>0; --i) {
            for(int j = 0; j<strfreq[i].length(); ++j) {
                for(int k = 0; k<i; ++k) ss<<strfreq[i][j];
            }
        }
        return ss.str();
    }
};