class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n-i-1; j++) {
                if(arr[j]<arr[j+1]) swap(arr[j],arr[j+1]);
            }
        }
        bool found =0;
        int i=0;
        while (!found && i<n) {
            int a = arr[i];
            int count =0;
            for (int j=0; j<n; j++) {
                if(arr[j]==a) {
                    count++;
                }                 
            }
            if(count==a) {
                found = 1;
                return a;
            }
            i++;
        }
        return -1;
    }
};