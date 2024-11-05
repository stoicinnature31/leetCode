class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else if(s[i] == ')' && !st.empty() && st.top() == '(') st.pop();
            else if(s[i] == '}' && !st.empty() && st.top() == '{') st.pop();
            else if(s[i] == ']' && !st.empty() && st.top() == '[') st.pop();
            else if(st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')) return 0;
            else st.push(s[i]);
        }
        if(st.empty()) return 1;
        else return 0;
    }
};