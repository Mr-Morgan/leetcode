class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int ans {static_cast<int>(s[0].length())};
        for(int i = 1; i < s.size(); i++) {
            int j = 0;
            while(j < s[i].length() && s[i][j] == s[0][j]) j++;
            ans = min(ans, j);
        }// for
        return s[0].substr(0, ans);
    }// string longestCommonPrefix()
};// Solution
