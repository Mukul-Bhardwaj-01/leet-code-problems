class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> seen;
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        queue<string> q;
        int ans = 0;
        q.push(beginWord);
        seen.insert(beginWord);
        int n = wordList.size();
        while(!q.empty()) {
            int size = q.size();
            ans++;
            for(int i = 0; i<size; ++i) {
                string word = q.front();
                if(word == endWord) return ans;
                q.pop();
                int wordLen = word.length();
                for(int j = 0; j < n; ++j) {
                    int cnt = 0;
                    for(int k = 0; k < wordLen; ++k) {
                        if(wordList[j][k] != word[k]) cnt++;
                        if(cnt > 1) break;
                    }
                    if(cnt == 1 && seen.find(wordList[j]) == seen.end()) {
                        q.push(wordList[j]);
                        seen.insert(wordList[j]);
                    }
                }
            }
        }
        return 0;
    }
};