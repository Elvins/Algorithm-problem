/**
双核处理
一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，假设已知CPU的每个核1秒可以处理1kb，每个核同时只能处理一项任务。n个任务可以按照任意顺序放入CPU进行处理，现在需要设计一个方案让CPU处理完这批任务所需的时间最少，求这个最小的时间。 
输入描述:
输入包括两行：
第一行为整数n(1 ≤ n ≤ 50)
第二行为n个整数length[i](1024 ≤ length[i] ≤ 4194304)，表示每个任务的长度为length[i]kb，每个数均为1024的倍数。


输出描述:
输出一个整数，表示最少需要处理的时间

输入例子:
5
3072 3072 7168 3072 1024

输出例子:
9216
**/
//思路：典型0-1背包问题。将length[i]数除1024，背包的容量为sum/2。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> length(n+1);
    length[0] = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> length[i];
        length[i] /= 1024;
        sum += length[i];
    }
    int len = sum/2;
    vector<vector<int> > dp(n+1, vector<int>(len+1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= len; j++){
            if(j < length[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j]  , dp[i-1][j-length[i]] + length[i]);
        }
    }
    cout << max(dp[n][len], sum-dp[n][len]) * 1024 << endl;
    return 0;
}
