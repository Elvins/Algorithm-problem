/**
消除重复元素
小易有一个长度为n序列，小易想移除掉里面的重复元素，但是小易想是对于每种元素保留最后出现的那个。小易遇到了困难,希望你来帮助他。 
输入描述:
输入包括两行：
第一行为序列长度n(1 ≤ n ≤ 50)
第二行为n个数sequence[i](1 ≤ sequence[i] ≤ 1000)，以空格分隔


输出描述:
输出消除重复元素之后的序列，以空格分隔，行末无空格

输入例子:
9
100 100 100 99 99 99 100 100 100

输出例子:
99 100
**/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n>50 || n<1)
        return 0;
    
    int number;
    int* sequence = new int[n];
    int flag[1010];
    memset(flag, 0, sizeof(flag));
    for(int i = 0; i < n; i++)
    {
        cin >> number;
        if(number>1000 || number<1)
            return 0;
        sequence[i] = number;
        flag[sequence[i]]++;
    }
    
    bool b = false;
    for(int i = 0; i < n; i++)
    {
        flag[sequence[i]]--;
        if(flag[sequence[i]] == 0)
        {
            if(!b)
            {
                b = true;
            }else
            {
                cout << " ";
            }
            cout << sequence[i];
        }
    }
    
    return 0;
}