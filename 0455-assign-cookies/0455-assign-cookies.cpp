class Solution {
public:
    int f(int i, int j, vector<int>& g, vector<int>& s){
        if(i >= g.size() || j >= s.size()) return 0;
        int assign = 0;
        if(s[j] >= g[i]) assign = 1 + f(i + 1, j + 1, g, s);
        else assign = f(i, j + 1, g, s);

        return assign;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        return f(0,0, g, s);
    }
};