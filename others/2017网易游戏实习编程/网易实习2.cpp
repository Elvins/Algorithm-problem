/**
时间限制：1秒
空间限制：65536K
题目描述
NTES是网易在纳斯达克股票市场的代号，在财报公布后，NTES的股价接连大涨，创下了历史新高。 下面，我们用四个5x7的点阵来描述NTES这代号。
##....#
#.#...#
#..#..#
#...#.#
#....##

#######
...#...
...#...
...#...
...#...

#######
#......
#######
#......
#######

#######
#......
#######
......#
####### 
假设我们认为每个点的周围的8个方向的点都和它是相连的，并且相连在一起的符号“#”我们可以认为在同一个联通分量，则上述四个点阵分别都包含了一个“#”的联通分量。

给定N * M的点阵，点阵只包含“.”和“#”两种符号。在点阵中可能包含了很多的联通分量。那么，在这点阵当中，你能找到多少个和标准的“N”,“T”,“E”,“S”一样的联通分量呢？
下面是点阵中NTES对应的联通分量的一些限制：
❖ N、T、E、S可能被顺时针旋转90度、180度或270度。例如以下的7x11的点阵中，包含了两个完整的T（两个联通分量），一个与前文提到的T方向一致，另一个是顺时针旋转了270度。
#...#######
#......#...
#......#...
#####..#...
#......#...
#..........
#..........
❖ 对于任何一个完整的N、T、E、S对应的联通分量，必须和前面给出的标准的模板一致。即除了旋转外，不多出或者缺少任何一个“#”，否则认为不匹配。例如下图中虽然只包含了一个联通分量（根据八方向相连的定义，（1,7）和（0,6）上的“#”相连），但是其多了一个“#”在位置（1,7），因此，以下点阵中没有任何一个NTES对应的联通分量。
#######.
...#...#
...#....
...#....
...#....

输入描述:
每个输入数据包含一个测试点。
第一行为点阵的大小N，M。其中1<=N<=500，1<=M<=500。
接下来N行，每行包含了M个“.”或“#”的字符，描述了给定的点阵。


输出描述:
输出包括四行，按顺序输出点阵中包含的NTES的数量。

输入例子:
输入样例1:
7 11
#...#######
#......#...
#......#...
#####..#...
#......#...
#..........
#..........


输入样例2:
12 23
#######....#....#######
...#...##....#..#......
#..#...#.#...#..#######
#..#...#..#..#........#
#...#..#...#.#..#######
###....#....##.........
.........#.............
#######....#.##.##....#
......#....#....#.#...#
#######....#....#..#..#
......#....#....#...#.#
#######.#######.#....##

输出例子:
输出样例1:
N: 0
T: 2
E: 0
S: 0


输出样例2:
N: 1
T: 1
E: 1
S: 1

**/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
char map[501][501];
bool a[501][501];
int N = 0, M = 0;

int walk(int i, int j)
{
    int value = 0;
    if(a[i][j] || map[i][j] != '#')
    {
        return value;
    }else
    {
        value += 1;
        a[i][j] = true;
    }
    
    //左上
    if((i-1)>=0 && j-1>=0 && map[i-1][j-1] == '#' && !a[i-1][j-1])
    {
        value += walk(i-1, j-1);
    }
    //上
    if((i-1)>=0 && j>=0 && map[i-1][j] == '#' && !a[i-1][j])
    {
        value += walk(i-1, j);
    }
    //右上
    if((i-1)>=0 && j+1< M && map[i-1][j+1] == '#' && !a[i-1][j+1])
    {
        value += walk(i-1, j+1);
    }
    //左
    if((i)>=0 && j-1>=0 && map[i][j-1] == '#' && !a[i][j-1])
    {
        value += walk(i, j-1);
    }
    //右
    if((i)>=0 && j+1<M && map[i][j+1] == '#' && !a[i][j+1])
    {
        value += walk(i, j+1);
    }
    //左下
    if((i+1)<N && j-1>=0 && map[i+1][j-1] == '#' && !a[i+1][j-1])
    {
        value += walk(i+1, j-1);
    }
    //下
    if((i+1)<N  && j>=0 && map[i+1][j] == '#'&& !a[i+1][j])
    {
        value += walk(i+1, j);
    }
    //右下
    if((i+1)<N && j+1< M && map[i+1][j+1] == '#' && !a[i+1][j+1])
    {
        value += walk(i+1, j+1);
    }
    
    return value;
}

int main()
{
    int n = 0;
    int t = 0;
    int e = 0;
    int s = 0;
    scanf("%d %d\n",&N,&M);
    for(int i = 0; i < N; i++)
    {
        char temp;
        for(int j = 0; j < M; j++)
        {
            scanf("%c",&map[i][j]);
            a[i][j] = false;
        }
        scanf("%c",&temp);
    }
    
   for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int value = walk(i, j);
            
            if(value == 15)
            {
                //判断是不是N
                //printf("N\n");
                bool flag1 = false;
                bool flag2 = false;
                for(int k = 0; k < 5; k++)
                {
                    if(i+6 >= N || j+k >= M || map[i+6][j+k] != '#'){
                        flag1 = true;
                    }
                    if(j+6 >= M || i+k >= N || map[i+k][j+6] != '#'){
                        flag2 = true;
                    }
                }
                if(flag1 && flag2)
                {
                    //printf("oh\n");
                    continue;
                }else if(flag1)
                {
                    //printf("flag1\n");
                    if(j+6 >= M)
                    {
                        continue;
                    }
                    bool tmp = false;
                    for(int k = 0; k < 5; k++)
                    {
                        if(map[i+k][j+k+1] != '#' || map[i+k][j+6] != '#')
                        {
                            tmp = true;
                            break;
                        }
                    }
                    if(tmp)
                    {
                        continue;
                    }else
                    {
                        n += 1;
                    }
                }else if(flag2)
                {
                    //printf("flag2\n");
                    if(i+6 >= N)
                    {
                        continue;
                    }
                    bool tmp = false;
                    for(int k = 0; k < 5; k++)
                    {
                        if(map[i+k+1][j+k] != '#' || map[i+6][j+k] != '#')
                        {
                            tmp = true;
                            break;
                        }
                    }
                    if(tmp)
                    {
                        continue;
                    }else
                    {
                        n += 1;
                    }
                }
            }
            if(value == 11)
            {
                //判断是不是T
                //printf("T\n");
                bool flag1 = false;
                bool flag2 = false;
                bool flag3 = false;
                for(int k = 1; k <= 6; k++)
                {
                    if(j+k >= M || map[i][j+k] != '#')
                    {
                        flag1 = true;
                    }
                    if(i+k >= N || map[i+k][j] != '#')
                    {
                        flag2 = true;
                        if(k <= 4)
                        {
                            flag3 = true;
                        }
                    }
                }
                if(flag1 && flag2 && flag3)
                {
                    //printf("oh\n");
                    continue;
                }else if(!flag2)
                {
                    //printf("flag2\n");
                    bool b1 = false;
                    bool b2 = false;
                    for(int p = 1; p < 5; p++)
                    {
                        if(j-p < 0 || map[i+3][j-p] != '#')
                        {
                            b1 = true;
                        }
                        if(j+p >= M || map[i+3][j+p] != '#')
                        {
                            b2 = true;
                        }
                    }
                    if(!b1 || !b2){
                        t += 1;
                    }else{
                        continue;
                    }
                }else if(!flag1)
                {
                    //printf("flag1\n");
                    bool b1 = false;
                    for(int p = 1; p < 5; p++)
                    {
                        if(i+p >= N || map[i+p][j+3] != '#')
                        {
                            b1 = true;
                        }
                    }
                    if(!b1){
                        t += 1;
                    }else{
                        continue;
                    }
                }else if(!flag3)
                {
                    //printf("flag3\n");
                    if(j-3 < 0 || j+3 >= M)
                    {
                        continue;
                    }
                    bool b1 = false;
                    for(int k = 0; k <= 6; k++)
                    {
                        if(map[i+4][j-3+k] != '#')
                        {
                            b1 = true;
                        }
                    }
                    if(!b1)
                    {
                        t += 1;
                    }
                }
                
            }
            if(value  == 23)
            {
                //判断是不是E/S
                bool flag1 = false;
                bool flag2 = false;
                //printf("E/S\n");
                for(int k = 0; k < 7; k++)
                {
                    if((j+k >= M || map[i][j+k] != '#')
                        || (i+2 >= N || j+k >= M || map[i+2][j+k] != '#')
                        || (i+4 >= N || j+k >= M || map[i+4][j+k] != '#'))
                    {
                        flag1 = true;
                    }
                    if((i+k >= N || map[i+k][j] != '#')
                        || (j+2 >=  M || i+k >= N || map[i+k][j+2] != '#')
                        || (j+4 >= M || i+k >= N || map[i+k][j+4] != '#'))
                    {
                        flag2 = true;
                    }
                }
                if(flag1 && flag2)
                {
                    //printf("oh\n");
                    continue;
                }else if(flag1)
                {
                    if(map[i][j+1] == '#' && map[i][j+3] == '#')
                    {
                        e += 1;
                    }else if(map[i+6][j+1] == '#' && map[i+6][j+3] == '#')
                    {
                        e += 1;
                    }else if(map[i+6][j+1] == '#' && map[i][j+3] == '#')
                    {
                        s += 1;
                    }
                }else if(flag2)
                {
                    if(map[i+1][j] == '#' && map[i+3][j] == '#')
                    {
                        e += 1;
                    }else if(map[i+1][j+6] == '#' && map[i+3][j+6] == '#')
                    {
                        e += 1;
                    }else if(map[i+1][j] == '#' && map[i+3][j+6] == '#')
                    {
                        s += 1;
                    }
                }
                
            }
        }
    }
    
    printf("N: %d\n",n);
    printf("T: %d\n",t);
    printf("E: %d\n",e);
    printf("S: %d\n",s);
    
    return 0;
}
