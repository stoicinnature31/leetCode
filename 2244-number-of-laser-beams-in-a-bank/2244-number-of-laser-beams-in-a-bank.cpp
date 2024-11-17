class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), first = -1, second = -1;
        int i = 0;
        // checking in which row find 1 first;
        while (i < n) {
            if (bank[i].find('1') != string::npos) {
                first = i;
                break;
            }
            i++;
        }
        i++;
        while (i < n) {
            if (bank[i].find('1') != string::npos) {
                second = i;
                break;
            }
            i++;
        }

        // count number of ones in each row
        vector<int> ones;
        for (auto i : bank) {
            int one = count(i.begin(), i.end(), '1');
            ones.push_back(one);
        }

        int beams = 0;
        if (first == -1 || second == -1) return 0;
        else {
            while (second < n) {
                int firstOne = ones[first];
                int secondOne = ones[second];
                beams += firstOne * secondOne;
                first = second;
                int i = first + 1;
                while (i < n) {
                    if (bank[i].find('1') != string::npos) {
                        second = i;
                        break;
                    }
                    i++;
                }
                if(second == first) break;
            }
        }
        return beams;
    }
};