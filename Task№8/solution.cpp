class Solution {
public:
    bool isMySpace (const char c) {
        constexpr char isspace {' '};
        return c == isspace;
    }// bool myisspace ()

    int isMySign (const char c) {
        constexpr char sign_minus {'-'}, sign_plus {'+'};
        if (c == sign_minus) return -1; 
        if (c == sign_plus) return 1;
        return 0;
    }// bool isMySign ()

    #define int_min numeric_limits<int>::min()
    #define int_max numeric_limits<int>::max()

    int isInt (const long n, const int sign) {
        if (sign == -1) {
            if (n*sign < int_min) return int_min;
        } else if (n > int_max) return int_max;
        return n;
    }// int isIntDivTen ()

    int myAtoi(string s) {

        size_t it {0};
        while (isMySpace(s[it]) && it < s.length()) it++;

        int sign {isMySign(s[it])};
        if (sign) it++;
        
        int num {0};
        while (isdigit(s[it]) && it < s.length()) {
            num = isInt(static_cast<long>(num)*10+(s[it]-'0'),sign);
            if (num == int_min || (sign != -1 && num == int_max)) return num;
            it++;
        }// while ()

        return (sign)?num*sign:num;
    }//int myAtoi()
};// Solution
