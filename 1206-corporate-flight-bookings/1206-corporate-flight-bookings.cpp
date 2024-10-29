class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for(auto i:bookings){
            int l = i[0], r = i[1], num =i[2];
            for(int i=l-1; i<r; i++){
                ans[i] += num;
            }
        }
        return ans;
    }
};