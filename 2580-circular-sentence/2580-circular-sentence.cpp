class Solution {
public:
    bool isCircularSentence(string sentence) {
        string temp = "";
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                if (i + 1 < sentence.size() &&
                    temp[temp.size() - 1] != sentence[i + 1]) {
                    temp.clear();
                    return 0;
                }
            } else
                temp += sentence[i];
        }
        if (temp[temp.size() - 1] != sentence[0]) {
            temp.clear();
            return 0;
        }
        return 1;
    }
};