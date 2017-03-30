/**
6. ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
**/

//发现所有行的重复周期都是 2 * nRows - 2
//对于非首行和非末行的行，还会额外重复一次，重复的这一次距离本周期起始字符的距离是 2 * nRows - 2 - 2 * i
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        string ans = "";
        
        //边缘情况
        if(len == 0 || numRows < 2){
            return s;
        }
        
        int cycle = 2*numRows-2;
        for(int i = 0; i < numRows; i++){
            for(int j = i; j < len; j += cycle){
                ans += s[j];
                
                //非首行、末行
                if(i > 0 && i < (numRows-1)){
                    int cycle_1 = cycle - (2*i) + j;
                    if(cycle_1 < len)
                        ans += s[cycle_1];
                }
            }
        }
        return ans;
    }
};