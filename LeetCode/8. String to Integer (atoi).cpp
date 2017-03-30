/**
8. String to Integer (atoi)
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
**/

/*
1. 字串为空或者全是空格，返回0； 
2. 字串的前缀空格需要忽略掉；
3. 忽略掉前缀空格后，遇到的第一个字符，如果是‘+’或‘－’号，继续往后读；如果是数字，则开始处理数字；如果不是前面的2种，返回0；
4. 处理数字的过程中，如果之后的字符非数字，就停止转换，返回当前值；
5. 在上述处理过程中，如果转换出的值超出了int型的范围，就返回int的最大值或最小值。
*/
class Solution {
public:
    int myAtoi(string str) {
        const int max = 0x7fffffff;
        const int min = 0x80000000;
        long long ans = 0;
        int flag = 1;
        int i = 0;
        
        //空字串
        if(str == ""){
            return 0;
        }

        while(str[i] == ' ' && str[i] != '\0'){
            i++;
        }

        if(str[i] == '\0'){
            return 0;
        }

        //+、-
        if(str[i] == '+'){
            flag = 1;
            i++;
        }else if(str[i] == '-'){
            flag = -1;
            i++;
        }

        //数字阶段
        while(str[i] != '\0'){
            if (str[i] >= '0' && str[i] <= '9'){
                 ans = ans*10 + flag*(str[i] - '0');
			}else{
                return ans;
			}
           
            if (ans > max || ans < min)   //溢出处理
                return ans > 0 ? max : min;
            ++i;
        }
		return ans;
    }
};