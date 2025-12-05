class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while(!s.empty() && s.back() == ' ') s.pop_back();
        while(i<(int)s.size() && s[i] == ' ') i++;
        s.erase(s.begin(),s.begin()+i);
        if(s.empty()) return "";
        int n = (int)s.size();
        int read = 0, write = 0;
        bool isPrevSpace = false;
        while(read<n) {
            if(s[read]!=' ') {
                s[write++] = s[read++];
                isPrevSpace = false;
            }
            else if(s[read] == ' ' && !isPrevSpace) {
                s[write++] = s[read++];
                isPrevSpace = true;
            }
            else if(s[read] == ' ' && isPrevSpace) {
                read++;
            }
        }
        s.resize(write);
        n=write;
        reverse(s.begin(),s.end());
        int start = 0, space = 0;
        while(space<n) {
            if(s[space] != ' ') space++;
            else if(s[space] == ' ') {
                reverse(s.begin()+start, s.begin()+space);
                space++;
                start=space;
            }
        }
        reverse(s.begin()+start, s.begin()+space);
        return s;
    }
};