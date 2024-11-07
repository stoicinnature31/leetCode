class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> winner;
        map<int, int> looser;

        for(auto i:matches){
            winner[i[0]]++;
            looser[i[1]]++;
        }

        vector<int> notLostOne;
        for(auto i:winner){
            if(looser.find(i.first) == looser.end()) notLostOne.push_back(i.first);
        }
        vector<int> lostExactlyOne;
        for(auto i:looser) if(i.second == 1) lostExactlyOne.push_back(i.first);

        vector<vector<int>> ans;
        ans.push_back(notLostOne);
        ans.push_back(lostExactlyOne);
        return ans;
        
    }
};