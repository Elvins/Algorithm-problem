/**
题目1 : 智力竞赛
时间限制:5000ms
单点时限:1000ms
内存限制:256MB
描述
小Hi、小Ho还有被小Hi强拉来的小Z，准备组队参加一个智力竞赛。竞赛采用过关制，共计N个关卡。在第i个关卡中，小Hi他们需要获得Ai点分数才能够进入下一关。每一关的分数都是独立计算的，即使在一关当中获得超过需要的分数，也不会对后面的关卡产生影响。

小Hi他们可以通过答题获得分数。答对一道题获得S点分数，答错一道题获得T点分数。在所有的N个关卡中，小Hi他们一共有M次答题机会。在每个关卡中，都可以在累计答题次数不超过M的情况下使用任意次的答题机会。

那么现在问题来了，对于给定的N、M、S、T和A，小Hi他们至少需要答对多少道题目才能够完成所有的关卡呢？

输入
每个输入文件包含多组测试数据，在每个输入文件的第一行为一个整数Q，表示测试数据的组数。

每组测试数据的第一行为四个正整数N、M、S和T，意义如前文所述。

第二行为N个正整数，分别表示A1~AN。

对于40%的数据，满足1<=N,M<=100

对于100%的数据，满足1<=N,M<=1000,1<=T<S<=10,1<=Ai<=50

对于100%的数据，满足1<=Q<=100

输出
对于每组测试数据，如果小Hi他们能够顺利完成关卡，则输出一个整数Ans，表示小Hi他们至少需要答对的题目数量，否则输出No。

样例输入
1
2 10 9 1
12 35
样例输出
5
**/

#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010][2];
//dp[i][j]表示答对i题，答错j题时，能达到的最好记录是什么
//dp[i][j][0]已经通关了几关、dp[i][j][1]、当前所在关累积多少分。
//dp[i][j] = max{dp[i-1][j] + S, dp[i][j-1] + T}
int guanqia[1010];
int main()
{
    int Q;
    cin >> Q;
    for(int cas = 0; cas < Q; cas++)
    {
        int  N, M, S, T;
        cin >> N >> M >> S >> T;
        memset(dp, 0, sizeof(dp));
        memset(guanqia, 0, sizeof(guanqia));
        int sum = 0;
        for(int i = 1; i <= N; i++)
        {
            cin >> guanqia[i];
            sum += guanqia[i];
        }
        if(sum > S * M)
        {
            cout << "No" << endl;
            continue;
        }

        int ans = -1;
        bool flag = true;
        for(int i = 0; i <= M && flag; i++)
        {
            for(int j = 0; j+i <= M && flag; j++)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }else if(i == 0)
                {
                    int score_t = dp[i][j-1][1] + T;
                    if(score_t >= guanqia[dp[i][j-1][0] + 1])
                    {
                        dp[i][j][0] = dp[i][j-1][0] + 1;
                        dp[i][j][1] = 0;
                    }else
                    {
                        dp[i][j][0] = dp[i][j-1][0];
                        dp[i][j][1] = score_t;
                    }
                }else if(j == 0)
                {
                    int score_s = dp[i-1][j][1] + S;
                    if(score_s >= guanqia[dp[i-1][j][0] + 1])
                    {
                        dp[i][j][0] = dp[i-1][j][0] + 1;
                        dp[i][j][1] = 0;
                    }else
                    {
                        dp[i][j][0] = dp[i-1][j][0];
                        dp[i][j][1] = score_s;
                    }
                }else
                {
                    int score_s = dp[i-1][j][1] + S;
                    int score_t = dp[i][j-1][1] + T;
                    int gate_s = dp[i-1][j][0];
                    int gate_t = dp[i][j-1][0];
                    if(score_s >= guanqia[dp[i-1][j][0] + 1])
                    {
                        gate_s = dp[i-1][j][0] + 1;
                        score_s = 0;
                    }
                    if(score_t >= guanqia[dp[i][j-1][0] + 1])
                    {
                        gate_t = dp[i][j-1][0] + 1;
                        score_t = 0;
                    }
                    //cout << "case i:" << i << " j:" << j << " score_s: " << score_s << " gate_s: " << gate_s << " score_t: " << score_t << " gate_t: " << gate_t<< endl;

                    if(gate_s > gate_t)
                    {
                        dp[i][j][0] = gate_s;
                        dp[i][j][1] = score_s;
                    }else if(gate_s < gate_t)
                    {
                        dp[i][j][0] = gate_t;
                        dp[i][j][1] = score_t;
                    }else
                    {
                        dp[i][j][0] = gate_s;
                        dp[i][j][1] = max(score_s, score_t);
                    }
                }
                if(dp[i][j][0] == N)
                {
                    ans = i;
                    flag = false;
                }
                //cout << "case i:" << i << " j:" << j << " dp[0]: " << dp[i][j][0] << " dp[1]: " << dp[i][j][1] << endl;
            }
        }
        if(ans != -1)
            cout << ans << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
