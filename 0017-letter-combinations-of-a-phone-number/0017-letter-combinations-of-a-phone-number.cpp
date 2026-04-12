class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> numMap = {{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, 
            {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};
        vector<string> ans;
        if(digits.size() == 1) {
            for(char c : numMap[digits[0]])
                ans.push_back(string(1, c));
        }
        else if(digits.size() == 2) {
            string t1 = numMap[digits[0]];
            string t2 = numMap[digits[1]];
            for(char c1 : t1)
                for(char c2 : t2)
                    ans.push_back(string(1,c1) + c2);
        }
        else if(digits.size() == 3) {
            string t1 = numMap[digits[0]];
            string t2 = numMap[digits[1]];
            string t3 = numMap[digits[2]];
            for(char c1 : t1)
                for(char c2 : t2)
                    for(char c3 : t3)
                        ans.push_back(string(1,c1) + c2 + c3);
        }
        else {
            string t1 = numMap[digits[0]];
            string t2 = numMap[digits[1]];
            string t3 = numMap[digits[2]];
            string t4 = numMap[digits[3]];
            for(char c1 : t1)
                for(char c2 : t2)
                    for(char c3 : t3)
                        for(char c4 : t4)
                            ans.push_back(string(1,c1) + c2 + c3 + c4);
        }
        return ans;
    }
};