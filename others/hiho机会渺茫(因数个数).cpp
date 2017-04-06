/**
题目1 : 机会渺茫
时间限制:5000ms
单点时限:1000ms
内存限制:256MB
描述
小Hi最近在追求一名学数学的女生小Z。小Z其实是想拒绝他的，但是找不到好的说辞，于是提出了这样的要求：对于给定的两个正整数N和M，小Hi随机选取一个N的约数N'，小Z随机选取一个M的约数M'，如果N'和M'相等，她就答应小Hi。

小Z让小Hi去编写这个随机程序，到时候她review过没有问题了就可以抽签了。但是小Hi写着写着，却越来越觉得机会渺茫。那么问题来了，小Hi能够追到小Z的几率是多少呢？

输入
每个输入文件仅包含单组测试数据。

每组测试数据的第一行为两个正整数N和M，意义如前文所述。

对于40%的数据，满足1<=N,M<=106

对于100%的数据，满足1<=N,M<=1012

输出
对于每组测试数据，输出两个互质的正整数A和B（以A分之B表示小Hi能够追到小Z的几率）。

样例输入
3 2
样例输出
4 1
**/

#include <bits/stdc++.h>
using namespace std;

#define MAX 10000005
int prime[MAX + 5], pcount=0;
bool flag[MAX + 5];
int en[MAX + 5], em[MAX + 5];
 
void init_prime()
{  
    memset(flag, false, sizeof(flag));
    pcount = 0;
    for (int i = 2; i <= MAX;i ++)
    {
        if (!flag[i])
        {
            prime[++pcount] = i;
            for(int j = i; j <= MAX / i; j++)
                flag[i * j] = true;
        }
    }
}
 
long long div(long long m, int *temp)  //约数个数定理：n=p1^a1×p2^a2×p3^a3*…*pk^ak, n的约数的个数就是(a1+1)(a2+1)(a3+1)…(ak+1)
{  
    long long tmp,ret=1;
    memset(temp, 0, sizeof(temp));
    int i;
    for(i = 1; prime[i] <= m && i <= pcount; i++)
    {
        if(m % prime[i] == 0)
        {
            tmp = 0;
            while(m % prime[i] == 0)
            {  
                tmp ++;  
                m /= prime[i];  
            }  
            ret = ret * (tmp+1);
            temp[prime[i]] = tmp;
        }  
    }
    return ret;  
}

long long solve()
{
    long long ret = 1;
    for (int i = 1; i <= pcount; i++)
    {
        if (en[prime[i]] && em[prime[i]])
        {
            int minn = min(en[prime[i]], em[prime[i]]);  //取最小的指数
            ret *= (minn + 1);
        }
    }
    return ret;
}

long long gcd(long long a, long long b)
{
    return b==0? a: gcd(b, a%b);
}

int main()
{
    init_prime();
    long long N, M;
    cin >> N >> M;
    
    long long n = div(N, en);
    long long m = div(M, em);
    long long x = solve();
    
    long long t = gcd(n, x);
    x = x / t;   
    n = n / t;

    t = gcd(m, x);
    x = x / t;
    m = m / t;
    n = n * m;
    
    cout << n << " " << x << endl;
    
    return 0;
}