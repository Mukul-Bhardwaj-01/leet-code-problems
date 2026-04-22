class Solution {
public:
    bool op(string &query, string &dictEle) {
        if(query == dictEle) return true;
        int n = query.length();
        int edits = 0;
        for(int i = 0; i<n; ++i) {
            if(query[i] != dictEle[i]) {
                edits++;
            }
            if(edits > 2) return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n = queries.size();
        for(string &i : queries) {
            for(string &a : dictionary) {
                if(op(i,a)) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};