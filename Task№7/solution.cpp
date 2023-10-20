#define INT_MIN numeric_limits<int>::min()
#define INT_MAX numeric_limits<int>::max()

class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x) {
            if (r > INT_MAX/10 || r < INT_MIN/10) return 0;
            r = r*10 + x%10;
            x = x / 10; 
        }// while () 
        return r;
    }// int reverse()
};// Solution
