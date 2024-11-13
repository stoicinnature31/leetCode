class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> temp;
        temp.push_back(0);
        int sum = 0;
        for(auto i:travel){
            sum += i;
            temp.push_back(sum);
        }
        int metal = 0, paper = 0, glass = 0, metalLast = -1, paperLast = -1, glassLast = -1;
        for(int i=0; i<garbage.size(); i++){
            for(auto j:garbage[i]){
                if(j == 'M'){
                    metal++;
                    metalLast = i;
                }
                if(j == 'P'){
                    paper++;
                    paperLast = i;
                }
                if(j == 'G'){
                    glass++;
                    glassLast = i;
                }
            }
        }
        if(metalLast != -1) metal += temp[metalLast];
        if(paperLast != -1) paper += temp[paperLast];
        if(glassLast != -1) glass += temp[glassLast];

        return (metal + paper + glass);
    }
};