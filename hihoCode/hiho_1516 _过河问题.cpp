/**
#1516 : 过河问题
时间限制:5000ms
单点时限:1000ms
内存限制:256MB
描述
小Hi最近游戏上瘾，就让小Ho找一个游戏给他玩。

小Ho想到了那个经典的农夫携狼、山羊、白菜过河的问题，进而回忆起从前玩过的八人过河游戏。

游戏规则是，警察、罪犯、父亲、母亲、两个男孩和两个女孩要过河，小船最多承载两人，只有警察、父亲和母亲能开船。在河的任意一岸或船上，都成立以下事件。

如果罪犯身边没有警察，则罪犯会攻击身边的所有人；如果罪犯身边没有人，则罪犯不会发动攻击。

如果父亲身边没有母亲，则父亲会攻击身边的女孩；如果父亲身边没有女孩，则父亲不会发动攻击。

如果母亲身边没有父亲，则母亲会攻击身边的男孩；如果父亲身边没有男孩，则父亲不会发动攻击。

游戏的目的是让八人在没有任何人发动攻击的情况下都顺利过河。

小Ho把这个游戏安利给小Hi，聪明的小Hi一下子就想出了解法。但小Hi并不满足，他将这个游戏归纳为了一个更具一般性的问题：

有n个人（编号0到n-1）要过河，其中某些人之间具有攻击或制约的单向关系，某些人具有掌舵能力。小船最多承载m个人。

如果B在A的身边，且A能攻击B，则A在不被制约的情况下会立刻攻击B。

如果C能制约A，则C在A的身边时A不能做出攻击行为。

一条船能够开动，仅当其上存在具有掌舵能力的人。

要求输出小船最少的渡河次数（从河的一岸到另一岸算1次），如果不能让所有人都顺利过河，输出-1。

小Hi希望你来玩这个游戏。

输入
第一行为正整数n (n <= 16)和m (m <= 16)，代表总人数与小船最大负载人数。

第二行为正整数a, b, c.

接下来a行，每行两个非负整数x和y，表示x能够攻击y。

接下来b行，每行两个非负整数x和y，表示x能够制约y。

接下来c行，每行一个非负整数x，表示x能够掌舵。

输出
输出仅一行，为最少渡河次数。如果不能顺利过河，输出-1。

样例输入
4 2
2 2 1
1 2
2 3
0 1
0 2
0
样例输出
7
**/
//思路：BFS+位运算表示
#include<bits/stdc++.h>
using namespace std;

int dp[2][1 << 16];
bool vis[2][1<<16];
int son[20], par[20];
int boat, tot;
int n, m, a, b, c;

bool safe(int x)
{
	for (int i = 0; i < n; i++)
    {
        if ((par[i] & x) == 0 && (son[i] & x) && (x >> i & 1))
            return 0;
    }
	return 1;
}

int main()
{
    cin >> n >> m >> a >> b >> c;
    while(a--)
    {
    	int u, v;
        cin >> u >> v;
    	son[u] |= 1 << v;
    }
    while(b--)
    {
    	int u, v;
        cin >> u >> v;
    	par[v] |= 1 << u;
    }
    while(c--)
    {
    	int x;
        cin >> x;
    	boat |= 1 << x;
    }
    tot = (1 << n) - 1; //用位来表示整体，如n=5，则tot=11111
    memset(dp, 0x3f, sizeof dp);
    memset(vis, 0, sizeof vis);
    dp[0][tot] = 0;
    queue<int> q;
    q.push(tot * 2);
    while(q.size())
    {
    	int sta = q.front();
        q.pop();
    	int u = sta >> 1; //当前开船位置的人员
    	int side = (sta & 1); //在哪一个岸边，0为开始的岸边，1为目标对岸
    	vis[side][u] = 0;
    	for(int i = u; i; i = (i-1&u))
        {
    		if(__builtin_popcount(i) > m || ((i & boat) == 0)) //乘船人数超过，或无人开船
                continue;
    		int v = tot ^ u ^ i;  //异或运算，i:乘船者，u:当前开船位置的人，v:船只运完人后对岸的人
    		if(!safe(i) || !safe(u ^ i) || !safe(v)) //不符合约束条件
                continue;
    		if(dp[side ^ 1][v] <= dp[side][u] + 1) //不是最优解
                continue;
    		dp[side^1][v] = dp[side][u] + 1;
    		int nxt = (v << 1) | (side ^ 1); //下一个搜索状态
    		if(!vis[side^1][v])
                q.push(nxt);
    		vis[side^1][v] = 1;
    	}
    }

    int ans = dp[1][tot];
    if(ans == 0x3f)
        ans = -1;
    cout << ans << endl;
    return 0;
}
