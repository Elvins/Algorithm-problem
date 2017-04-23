/**
#1515 : 分数调查
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
小Hi的学校总共有N名学生，编号1-N。学校刚刚进行了一场全校的古诗文水平测验。

学校没有公布测验的成绩，所以小Hi只能得到一些小道消息，例如X号同学的分数比Y号同学的分数高S分。

小Hi想知道利用这些消息，能不能判断出某两位同学之间的分数高低？

输入
第一行包含三个整数N, M和Q。N表示学生总数，M表示小Hi知道消息的总数，Q表示小Hi想询问的数量。

以下M行每行三个整数，X, Y和S。表示X号同学的分数比Y号同学的分数高S分。

以下Q行每行两个整数，X和Y。表示小Hi想知道X号同学的分数比Y号同学的分数高几分。

对于50%的数据，1 <= N, M, Q <= 1000

对于100%的数据，1 <= N, M, Q<= 100000 1 <= X, Y <= N -1000 <= S <= 1000

数据保证没有矛盾。

输出
对于每个询问，如果不能判断出X比Y高几分输出-1。否则输出X比Y高的分数。

样例输入
10 5 3
1 2 10
2 3 10
4 5 -10
5 6 -10
2 5 10
1 10
1 5
3 5
样例输出
-1
20
0
**/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+100 ;
int par[maxn];
int dis[maxn];

int Find(int x) {
	if(par[x] == x)
        return x;
	int temp = par[x];
	par[x] = Find(par[x]);
	dis[x] += dis[temp];
	return par[x];
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i <= n; i++)
    {
        par[i] = i;
        dis[i] = 0;
    }
	while(m--)
    {
		int u, v, s;
		cin >> u >> v >> s;
		if (s < 0)
		{
		    swap(u, v);
		    s = -s;
		}
		int pu = Find(u);
		int pv = Find(v);
		if(pu == pv)
            continue;
		if(s + dis[u] > dis[v])
        {
            par[pv] = pu;
            dis[pv] = s + dis[u] - dis[v];
        }else
        {
            par[pu] = pv;
            dis[pu] = dis[v] - s - dis[u];
        }
	}
	while (q--)
    {
		int u, v;
		cin >> u >> v;
		int pu = Find(u);
        int pv = Find(v);
		if(pu != pv)
            cout << -1 << endl;
		else
			cout << dis[v] - dis[u] << endl;
	}
    return 0;
}
