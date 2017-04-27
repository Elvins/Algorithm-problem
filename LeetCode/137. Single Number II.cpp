/**
137. Single Number II
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


思路：
在这道题中，需要做的是存储的每一点1的数量。因为32位整型中的每个位的遵循相同的规则,故我们只考虑1位。
由题得，除了目标以外都出现最多3次,所以我们需要2位来存储每一位的状态。现在我们有4个状态,00,01,10和11,但只需要3种状态即可。
在这个解决方案中,选择00,01和10这三个状态。a是第一位,b是第二位。
为表示完整的循环00 - > 10 - > 01 - > 00(0 - > 1 - > 2 - > 3/0)，设置以下规则：
1、对于a, 通过异或运算：a = a ^ nums[i]; 如果b==1,则a为0。故a = (a ^ nums[i]) & ~b；
2、对于b，通过异或运算：b = b ^ nums[i]; 如果a==1,则b为0。故b = (b ^ nums[i]) & ~a；
ps:需要注意第二个规则中的a为计算后的a，之后再进行b的计算。
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for(int i = 0; i < nums.size(); i++){
            cout << a << " " << b << " " << nums[i] << " ";
            a = (a ^ nums[i]) & ~b;
            b = (b ^ nums[i]) & ~a;
            cout << a << " " << b << endl;
        }
        return a;
    }
};

