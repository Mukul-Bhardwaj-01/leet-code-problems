class Solution {
public:
    vector<bool> sieve(int maxVal) {
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxVal; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxVal; j += i)
                    isPrime[j] = false;
            }
        }
        return isPrime;
    }

    vector<int> getPrimeFactors(int num, const vector<bool>& isPrime) {
        vector<int> factors;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0 && isPrime[i]) {
                factors.push_back(i);
                while (num % i == 0) num /= i;
            }
        }
        if (num > 1 && isPrime[num]) {
            factors.push_back(num);
        }
        return factors;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        vector<int> mordelvian = nums; // As required

        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime = sieve(maxVal);

        unordered_map<int, vector<int>> primeToIndices;

        // Build reverse map: prime → list of indices
        for (int i = 0; i < n; ++i) {
            vector<int> pf = getPrimeFactors(nums[i], isPrime);
            for (int p : pf) {
                primeToIndices[p].push_back(i);
            }
        }

        queue<int> q;
        vector<bool> visited(n, false);
        unordered_set<int> usedPrimes;
        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int i = q.front(); q.pop();
                if (i == n - 1) return steps;

                // Step to i + 1
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                // Step to i - 1
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                // Prime teleportation only if nums[i] is prime
                if (isPrime[nums[i]] && !usedPrimes.count(nums[i])) {
                    for (int j : primeToIndices[nums[i]]) {
                        if (!visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                    usedPrimes.insert(nums[i]);
                }
            }
            ++steps;
        }

        return -1;
    }
};
