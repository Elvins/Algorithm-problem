/**
9. Palindrome Number
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.
**/

class Solution {
public:
    bool isPalindrome(int x) {
        //负数
        if(x < 0){
            return false;
        }
        if(x == 0){
            return true;
        }
        
        int multiple_10 = 1;
        while(x / multiple_10 >= 10){
            multiple_10 *= 10;
        }
        
        while(x > 0){
            int l = x / multiple_10;
            int r = x % 10;
            if(l != r){
                return false;
            }
            //去头尾
            x = (x % multiple_10) / 10;
            multiple_10 /= 100;
        }
        return true;
    }
};