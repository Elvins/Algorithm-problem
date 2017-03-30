/**
7. Reverse Integer
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
**/

class Solution {
public:
    int reverse(int x) {
        //考虑溢出情况
        const int max = 0x7fffffff;
        const int min = 0x80000000;
        
        long long ans = 0;
        while(x){
            ans = ans*10 + x%10;
            x = x/10;
            //溢出判断
            if(ans > max || ans < min){
                //return (ans > 0 ? max : min);
                return 0;
            }
        }
        return ans;
    }
};