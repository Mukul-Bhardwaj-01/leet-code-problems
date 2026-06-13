class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        stringstream s;
        for(string &word : words) {
            int weight = 0;
            for(char &c : word) {
                weight += weights[c - 97];
                weight %= 26;
            }
            s << (char)(122 - weight);
        }
        return s.str();
    }
};