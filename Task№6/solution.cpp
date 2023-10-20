class Solution {
public:
    string convert(const string &s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) return s;
        string z;
        int shift = numRows + numRows - 2;
        for (int i = 0, row_count = 0; row_count < numRows; i+= shift) {
            if (row_count == 0) { // first row
                if (i < s.length()) z += s[i];
            } else if(row_count != numRows-1) {
                if (i-row_count > 0 && i-row_count < s.length()) z += s[i-row_count];
                if (i+row_count < s.length()) z += s[i+row_count];
            } else if (i+row_count < s.length()) z += s[i+row_count]; // last row
            
            if (i > s.length()-1) {
                row_count++;
                i = - shift;
            }// if ()
        }// for ()
        return z;
    }// string convert()
};// Solution
