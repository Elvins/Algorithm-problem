/**
137. Single Number II
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


˼·��
��������У���Ҫ�����Ǵ洢��ÿһ��1����������Ϊ32λ�����е�ÿ��λ����ѭ��ͬ�Ĺ���,������ֻ����1λ��
����ã�����Ŀ�����ⶼ�������3��,����������Ҫ2λ���洢ÿһλ��״̬������������4��״̬,00,01,10��11,��ֻ��Ҫ3��״̬���ɡ�
��������������,ѡ��00,01��10������״̬��a�ǵ�һλ,b�ǵڶ�λ��
Ϊ��ʾ������ѭ��00 - > 10 - > 01 - > 00(0 - > 1 - > 2 - > 3/0)���������¹���
1������a, ͨ��������㣺a = a ^ nums[i]; ���b==1,��aΪ0����a = (a ^ nums[i]) & ~b��
2������b��ͨ��������㣺b = b ^ nums[i]; ���a==1,��bΪ0����b = (b ^ nums[i]) & ~a��
ps:��Ҫע��ڶ��������е�aΪ������a��֮���ٽ���b�ļ��㡣
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

