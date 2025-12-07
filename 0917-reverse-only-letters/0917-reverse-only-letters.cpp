class Solution {
public:
    string reverseOnlyLetters(string s) {
        int low = 0, high = s.length()-1;
        while(low<=high) {
            if(isalpha(static_cast<unsigned char>(s[low])) && isalpha(static_cast<unsigned char>(s[high]))) 
                swap(s[low++],s[high--]);
            else if(isalpha(static_cast<unsigned char>(s[low]))) high--;
            else if(isalpha(static_cast<unsigned char>(s[high]))) low++;
            else {
                low++;
                high--;
            }
        }
        return s;
    }
};