/**
#1515 : ��������
ʱ������:10000ms
����ʱ��:1000ms
�ڴ�����:256MB
����
СHi��ѧУ�ܹ���N��ѧ�������1-N��ѧУ�ոս�����һ��ȫУ�Ĺ�ʫ��ˮƽ���顣

ѧУû�й�������ĳɼ�������СHiֻ�ܵõ�һЩС����Ϣ������X��ͬѧ�ķ�����Y��ͬѧ�ķ�����S�֡�

СHi��֪��������Щ��Ϣ���ܲ����жϳ�ĳ��λͬѧ֮��ķ����ߵͣ�

����
��һ�а�����������N, M��Q��N��ʾѧ��������M��ʾСHi֪����Ϣ��������Q��ʾСHi��ѯ�ʵ�������

����M��ÿ������������X, Y��S����ʾX��ͬѧ�ķ�����Y��ͬѧ�ķ�����S�֡�

����Q��ÿ������������X��Y����ʾСHi��֪��X��ͬѧ�ķ�����Y��ͬѧ�ķ����߼��֡�

����50%�����ݣ�1 <= N, M, Q <= 1000

����100%�����ݣ�1 <= N, M, Q<= 100000 1 <= X, Y <= N -1000 <= S <= 1000

���ݱ�֤û��ì�ܡ�

���
����ÿ��ѯ�ʣ���������жϳ�X��Y�߼������-1���������X��Y�ߵķ�����

��������
10 5 3
1 2 10
2 3 10
4 5 -10
5 6 -10
2 5 10
1 10
1 5
3 5
�������
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
