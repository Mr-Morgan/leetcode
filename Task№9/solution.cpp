/*
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;  
    }// bool isPalindrome()
};// Solution
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        uint64_t top = 1;
        while (top <= x) top *= 10;
        
        top /= 10;
        int bottom = 1;
        while (bottom < top) {
            if ((x/top)%10 != (x/bottom)%10) return false;
            top /= 10;
            bottom *= 10;
        }// while ()
        return true;
    }// bool isPalindrome ()
};// Solution
