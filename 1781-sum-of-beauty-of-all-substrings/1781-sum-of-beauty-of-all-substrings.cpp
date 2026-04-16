class Solution {
public:
    int beautySum(string s) {
        int n = s.length(), sum = 0;
        for(int i = 0; i<n - 1; ++i) {
            vector<int> freq(26,0);
            freq[s[i] - 'a']++;
            for(int j = i + 1; j<n; ++j) {
                freq[s[j] - 'a']++;
                int minFreq = INT_MAX, maxFreq = INT_MIN;
                for(int k = 0; k<26; ++k) {
                    if(freq[k] > 0) {
                        minFreq = min(minFreq, freq[k]);
                        maxFreq = max(maxFreq, freq[k]);
                    }
                }
                sum += (maxFreq - minFreq);
            }
        }
        return sum;
    }
};