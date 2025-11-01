class Solution {
public:
    static bool comp(pair<char,int>& p1, pair<char,int>& p2) {
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        string result = "";
        vector<pair<char, int>> hashvec;
        for(char c : s) {
            auto it = find_if(hashvec.begin(),hashvec.end(),
            [c](const pair<char,int>& p) {return p.first == c;});
            if(it != hashvec.end()) {
                int indx = it - hashvec.begin();
                hashvec[indx].second++;
            }
            else hashvec.push_back({c,1});
        }
        sort(hashvec.begin(),hashvec.end(), comp);
        for(int i = 0; i<hashvec.size(); ++i) {
            for(int j = 0; j<hashvec[i].second; ++j) {
                result+=hashvec[i].first;
            }
        }
        return result;
    }
};