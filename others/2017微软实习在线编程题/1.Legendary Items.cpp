/**
题目1 : Legendary Items
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
Little Hi is playing a video game. Each time he accomplishes a quest in the game, Little Hi has a chance to get a legendary item.

At the beginning the probability is P%. Each time Little Hi accomplishes a quest without getting a legendary item, the probability will go up Q%. Since the probability is getting higher he will get a legendary item eventually.

After getting a legendary item the probability will be reset to ⌊P/(2I)⌋% (⌊x⌋ represents the largest integer no more than x) where I is the number of legendary items he already has. The probability will also go up Q% each time Little Hi accomplishes a quest until he gets another legendary item.

Now Little Hi wants to know the expected number of quests he has to accomplish to get N legendary items.  

Assume P = 50, Q = 75 and N = 2, as the below figure shows the expected number of quests is

2*50%*25% + 3*50%*75%*100% + 3*50%*100%*25% + 4*50%*100%*75%*100% = 3.25

legendary.png

输入
The first line contains three integers P, Q and N.  

1 ≤ N ≤ 106, 0 ≤ P ≤ 100, 1 ≤ Q ≤ 100

输出
Output the expected number of quests rounded to 2 decimal places.

样例输入
50 75 2
样例输出
3.25
**/

//由于每拿到一个的事件都是独立的，只是P值改变。故可以等价为 FUNC(PN) + FUNC(PN/2) + FUNC(PN/4) +.......
//FUNC(PN)为在当前PN的概率下拿到一次的期望

#include <bits/stdc++.h>
using namespace std;

double func(int Pn, int Qn){
    double p = Pn/100.0;
    double q = Qn/100.0;
    double sum = p;   //初始化一次拿到
    double temp = 1.0;
    for(int i = 1; p + q*(i-1) <= 1; i++)
    {
        temp *= (1-(p+q*(i-1))); //一次拿不到的概率
        if(p + q*i >= 1)
        {
            sum += (i+1) * temp;
        }else
        {
            sum += (i+1) * temp * (p + q*i);
        }
    }
    return sum;
}

int main()
{
    int P, Q, N;
    cin >> P >> Q >> N;
    
    double ans = 0.0;
    int tmp = P;
    for(int i = 0; i < N; i++)
    {
        ans += func(tmp, Q);
        tmp = tmp >> 1;
    }
    
    cout << setprecision(3) << ans << endl;
    
    return 0;
}