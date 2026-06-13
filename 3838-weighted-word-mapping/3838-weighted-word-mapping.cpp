class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s = "";
        for(string &word : words) {
            int weight = 0;
            for(char &c : word) {
                weight += weights[c - 97];
                weight %= 26;
            }
            s += (122 - weight);
        }
        return s;
    }
};