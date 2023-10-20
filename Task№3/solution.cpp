class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	constexpr int alphabet {256};
        int lastOcc[alphabet] = {0};
        int start {0}, end {0}, res {0};

        while(end < s.size()){
            start = std::max(start, lastOcc[s[end]]);
            res = std::max(res, end - start + 1);
            lastOcc[s[end]] = end + 1;
            end++;
        }//while()

        return res;
    }//int lengthOfLongestSubstring()
};// Solution
