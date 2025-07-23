class Solution {
public:
    int maximumGain(string s, int x, int y) {
        return x > y ? 
            process(s, 'a', 'b', x, y) : 
            process(s, 'b', 'a', y, x);
    }
    
private:
    int process(string s, char first, char second, int high, int low) {
        int score = 0;
        string temp;

        // First pass: remove high scoring pair (either "ab" or "ba")
        for (char c : s) {
            if (!temp.empty() && temp.back() == first && c == second) {
                temp.pop_back();
                score += high;
            } else {
                temp.push_back(c);
            }
        }

        // Second pass: remove remaining low scoring pair (reverse order)
        string finalStr;
        for (char c : temp) {
            if (!finalStr.empty() && finalStr.back() == second && c == first) {
                finalStr.pop_back();
                score += low;
            } else {
                finalStr.push_back(c);
            }
        }

        return score;
    }
};
