/**
��Ŀ1 : ��������
ʱ������:5000ms
����ʱ��:1000ms
�ڴ�����:256MB
����
СHi��СHo���б�СHiǿ������СZ��׼����Ӳμ�һ�������������������ù����ƣ�����N���ؿ����ڵ�i���ؿ��У�СHi������Ҫ���Ai��������ܹ�������һ�ء�ÿһ�صķ������Ƕ�������ģ���ʹ��һ�ص��л�ó�����Ҫ�ķ�����Ҳ����Ժ���Ĺؿ�����Ӱ�졣

СHi���ǿ���ͨ�������÷��������һ������S����������һ������T������������е�N���ؿ��У�СHi����һ����M�δ�����ᡣ��ÿ���ؿ��У����������ۼƴ������������M�������ʹ������εĴ�����ᡣ

��ô�����������ˣ����ڸ�����N��M��S��T��A��СHi����������Ҫ��Զ��ٵ���Ŀ���ܹ�������еĹؿ��أ�

����
ÿ�������ļ���������������ݣ���ÿ�������ļ��ĵ�һ��Ϊһ������Q����ʾ�������ݵ�������

ÿ��������ݵĵ�һ��Ϊ�ĸ�������N��M��S��T��������ǰ��������

�ڶ���ΪN�����������ֱ��ʾA1~AN��

����40%�����ݣ�����1<=N,M<=100

����100%�����ݣ�����1<=N,M<=1000,1<=T<S<=10,1<=Ai<=50

����100%�����ݣ�����1<=Q<=100

���
����ÿ��������ݣ����СHi�����ܹ�˳����ɹؿ��������һ������Ans����ʾСHi����������Ҫ��Ե���Ŀ�������������No��

��������
1
2 10 9 1
12 35
�������
5
**/

#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010][2];
//dp[i][j]��ʾ���i�⣬���j��ʱ���ܴﵽ����ü�¼��ʲô
//dp[i][j][0]�Ѿ�ͨ���˼��ء�dp[i][j][1]����ǰ���ڹ��ۻ����ٷ֡�
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
