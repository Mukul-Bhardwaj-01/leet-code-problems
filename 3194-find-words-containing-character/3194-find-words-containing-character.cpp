#include <stack>
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> A;
        for (int i=0; i<words.size(); i++) {
            for(int j=0; j<words[i].size(); j++) {
                if(words[i][j]==x) {
                    A.push_back(i);
                    break;
                }
            }
        }
        return A;
    }
};