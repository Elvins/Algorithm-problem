/**
时间限制：1秒
空间限制：65536K
题目描述
小Q是名小学生，他最喜欢数学中的加法竖式填空了。例如下面的填空题，每个空格表示1…9中的一个数字。
 
有时候这种竖式题不一定只有唯一解，小Q很想知道，给定一个这样的竖式，总共可能的解有多少个。
被加数和加数的位数不会超过3位。和的位数不会超过4位。空格只可能存在于被加数和加数中。

输入描述:
每个输入数据包含多个测试点。
第一行为测试点的个数T(T<=30)。
每个测试点包含一行，包含了三个长度大于0的字符串，分别表示被加数，加数和结果。每个字符串之间有一个空格。每个字符串只会包含“X”和“1”…“9”，其中“X”表示竖式中的空格。保证竖式至少有一个解。


输出描述:
对于每个测试点，输出一行，表示一共可能的解的个数。

输入例子:
2
X7 9X 123
X X 4

输出例子:
1
3
（样例解释：样例1的解为27+96，样例2的解为1+3,2+2,3+1。）
**/

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int res, cnt;
int kongge[10];

void dfs(int rest,int num)
{
    if(rest < 0)
    {
        return;
    }
	if(num == cnt)
	{
		if(rest == 0)
			res++;
		return;
	}
	for(int i = 1; i <= 9; i++)
		dfs(rest-kongge[num]*i, num+1);
}

int main()
{
	int T;
	scanf("%d", &T);
	char jia1[10], jia2[10], he[10];
	for(int cas = 1; cas <= T; cas++)
	{
		memset(kongge, 0, sizeof(kongge));
		scanf("%s%s%s", jia1, jia2, he);
		int sum1 = 0,sum2 = 0;
		cnt = 0;
		res = 0;
		for(int i = 0; i < strlen(he); i++)
		{
			sum1 = sum1 * 10 + he[i] - '0';
		}
		int temp = 1;
		for(int i = strlen(jia1)-1; i >= 0; i--)
		{
			if(jia1[i] == 'X')
			{
				kongge[cnt++] = temp;
				temp *= 10;
				continue;
			}
			sum2 += temp * (jia1[i] - '0');
			temp *= 10;
		}
		temp = 1;
		for(int i = strlen(jia2)-1; i >= 0; i--)
		{
			if(jia2[i] == 'X')
			{
				kongge[cnt++] = temp;
				temp *= 10;
				continue;
			}
			sum2 += temp * (jia2[i] - '0');
			temp *= 10;
		}
		int rest=sum1-sum2;
//		printf("%d %d %d %d\n",sum1,sum2,rest,cnt);
//		for(int i=0;i<cnt;i++)
//			printf("%d\n",kongge[i]);
		dfs(rest, 0);
		printf("%d\n", res);
//		printf("%d\n",sum);
	}
    
    return 0;
}
