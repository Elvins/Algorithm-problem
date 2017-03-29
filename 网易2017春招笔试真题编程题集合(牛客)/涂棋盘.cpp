/**
涂棋盘
小易有一块n*n的棋盘，棋盘的每一个格子都为黑色或者白色，小易现在要用他喜欢的红色去涂画棋盘。小易会找出棋盘中某一列中拥有相同颜色的最大的区域去涂画，帮助小易算算他会涂画多少个棋格。 
输入描述:
输入数据包括n+1行：

第一行为一个整数n(1 ≤ n ≤ 50),即棋盘的大小

接下来的n行每行一个字符串表示第i行棋盘的颜色，'W'表示白色，'B'表示黑色


输出描述:
输出小易会涂画的区域大小

输入例子:
3
BWW
BBB
BWB

输出例子:
3
**/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> qipan;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        qipan.push_back(s);
    }
    
    int W = 0;
    int B = 0;
    for(int i = 0; i < n; i++)
    {
        int subw = 0, subb = 0;
        for(int j = 0; j < n; j++)
        {
            if(qipan[j][i] == 'B')
            {
                subb++;
                subw = 0;
                if(subb > B)
                    B = subb;
            }
            if(qipan[j][i] == 'W')
            {
                subw++;
                subb = 0;
                if(subw > W)
                    W = subw;
            }
        }
    }
    int ans = (W >= B) ? W : B;
    cout << ans << endl;
    
    return 0;
}