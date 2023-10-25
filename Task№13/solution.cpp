class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for(int i = 0; i<s.length(); i++) {
            switch(s[i]) {
                case 'I':
                    if (s[i+1] == 'V' || s[i+1] == 'X') num = num - 1;
                    else num = num + 1;
                    break;
                case 'V':
                    num = num + 5;
                    break;
                case 'X':
                    if (s[i+1] == 'L' || s[i+1] == 'C') num = num - 10;
                    else num = num + 10;
                    break;
                case 'L':
                    num = num + 50;
                    break;
                case 'C':
                    if (s[i+1] == 'D' || s[i+1] == 'M') num = num - 100;
                    else num = num + 100;
                    break;
                case 'D':
                    num = num + 500;
                    break;
                case 'M':
                    num = num + 1000;
                    break;
            }// switch()
        }// for()
        return num;
    }// int romanToInt()
};// Solution
