class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        // If endWord not present, no possible transformation
        if(st.find(endWord) == st.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string word = q.front();
                q.pop();
                if(word == endWord) return steps;
                // Try all possible one-letter transformations
                for(int i = 0; i < word.length(); i++) {
                    char original = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        // If valid word found in dictionary
                        if(st.find(word) != st.end()) {
                            q.push(word);
                            st.erase(word); // mark visited
                        }
                    }
                    word[i] = original; // restore
                }
            }
            steps++;
        }
        return 0;
    }
};