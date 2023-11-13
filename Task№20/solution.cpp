class Solution {
public:
    bool isValid(string s) {
        if (s.length()%2) return false;
        string tmp = "";
        for (auto marker: s) {
            switch (marker) {
                case '(': case '[': case '{':
                    tmp += marker; 
                    break;
                case ')': 
                    if (tmp.back() != '(') return false;
                    if (tmp.length()) tmp.pop_back();
                    else return false;
                    break;
                case ']': 
                    if (tmp.back() != '[') return false;
                    if (tmp.length()) tmp.pop_back();
                    else return false;
                    break;
                case '}':
                    if (tmp.back() != '{') return false;
                    if (tmp.length()) tmp.pop_back();
                    else return false;
                    break;
            }// switch
        }// while
        return !tmp.length(); 
    }// bool isValid()
};// Solution
