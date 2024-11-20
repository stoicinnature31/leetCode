class Solution {
public:
    int minOperations(int n) {
        int mid;
        int ans = 0;
        if(n & 1) mid = 2 * (n / 2) + 1;
        else {
            int mid1 = 2 * (n / 2 - 1) + 1;
            int mid2 = 2 * (n / 2) + 1;
            mid = (mid1 + mid2) / 2;
        }
        for(int i=0; i<n/2; i++) ans += mid - ((2 * i) + 1);
        return ans;
    }
};