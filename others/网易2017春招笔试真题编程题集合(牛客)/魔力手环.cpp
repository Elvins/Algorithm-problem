/**
小易拥有一个拥有魔力的手环上面有n个数字(构成一个环),当这个魔力手环每次使用魔力的时候就会发生一种奇特的变化：每个数字会变成自己跟后面一个数字的和(最后一个数字的后面一个数字是第一个),一旦某个位置的数字大于等于100就马上对100取模(比如某个位置变为103,就会自动变为3).现在给出这个魔力手环的构成，请你计算出使用k次魔力之后魔力手环的状态。 
输入描述:
输入数据包括两行：
第一行为两个整数n(2 ≤ n ≤ 50)和k(1 ≤ k ≤ 2000000000),以空格分隔
第二行为魔力手环初始的n个数，以空格分隔。范围都在0至99.


输出描述:
输出魔力手环使用k次之后的状态，以空格分隔，行末无空格。

输入例子:
3 2
1 2 3

输出例子:
8 9 7

思路：可转化为矩阵相乘
设：
    M[n*n]，为变换矩阵，例如例子中的变换矩阵为：[1,1,0]
                                                [0,1,1]
                                                [1,0,1]
    seq[n * 1]为魔力换数字向量
    变化K次为：M矩阵的K次方 * seq[n]，故可以使用矩阵的快速幂相乘
    
一个数的快速幂如下：
int pow(int a, int n) 
{
    int res = 1;
    while (n) {
        if (n % 2)
            res *= a;
        a *= a;
        n = n >> 1;
    }
    return res;
}
**/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

//矩阵乘法函数
vector<vector<int> > multi(const vector<vector<int> > &m,const vector<vector<int> > &n) 
{
    int a = m.size(), b = m[0].size(), c = n[0].size();
    vector<vector<int> > res(a, vector<int>(c, 0));
    for (int i = 0; i < a; i++)
        for (int j = 0; j < c; j++)
            for (int k = 0; k < b; k++)
                res[i][j] = (res[i][j] + m[i][k] * n[k][j]) % 100; //根据题目取模
    return res;
}
//矩阵的快速幂
vector<vector<int> > q_pow(vector<vector<int> > m, int n) 
{
    vector<vector<int> > res(m.size(), vector<int>(m.size(),0));
    //初始化一个单位矩阵
    for (int i = 0; i < m.size(); i++)
        res[i][i] = 1;
    while (n) 
    {
        if (n % 2)
            res = multi(res, m);
        m = multi(m, m);
        n = n >> 1;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> seq(n);
    for(int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }
    
    //构造变化矩阵
    vector<vector<int> > M(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) 
    {
        M[i][i] = M[i][(i + 1) % n] = 1;
    }
    
    vector<vector<int> > R = q_pow(M, k);

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) 
            sum = (sum + R[i][j] * seq[j]) % 100;
        ans.push_back(sum);
    }
    for(int i = 0; i < ans.size(); i++)
    {
        i == 0 ? cout << ans[i] : cout << " " << ans[i];
    }

    return 0;
}