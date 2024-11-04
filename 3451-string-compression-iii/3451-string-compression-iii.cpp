class Solution {
public:
    string compressedString(string word) {

        string comp = "";
        string temp = "";
        char newChar = word[0];

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == newChar) {
                temp.push_back(word[i]);
            } else {
                if (!temp.empty()) comp += to_string(temp.size()) + temp[0];
                newChar = word[i];
                temp.clear();
                temp.push_back(word[i]);
            }

            if (temp.size() == 9) { // When temp reaches 9, add "9<char>" and clear
                comp += "9";
                comp += temp[0];
                temp.clear();
            }
        }

        // Handle remaining characters in temp after loop ends
        int n = temp.size();
        while (n > 0) {
            if (n >= 9) {
                comp += "9" + temp[0];
                n -= 9;
            } else {
                comp += to_string(n) + temp[0];
                n = 0;
            }
        }

        return comp;
    }
};
