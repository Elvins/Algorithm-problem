/**
堆砖块
小易有n块砖块，每一块砖块有一个高度。小易希望利用这些砖块堆砌两座相同高度的塔。为了让问题简单，砖块堆砌就是简单的高度相加，某一块砖只能使用在一座塔中一次。小易现在让能够堆砌出来的两座塔的高度尽量高，小易能否完成呢。 
输入描述:
输入包括两行：
第一行为整数n(1 ≤ n ≤ 50)，即一共有n块砖块
第二行为n个整数，表示每一块砖块的高度height[i] (1 ≤ height[i] ≤ 500000)


输出描述:
如果小易能堆砌出两座高度相同的塔，输出最高能拼凑的高度，如果不能则输出-1.
保证答案不大于500000。

输入例子:
3
2 3 5

输出例子:
5
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        h.push_back(t);
        sum += t;
    }
    
    /**
    动态规划,利用滚动数组
    从没有砖块开始分析。考虑每块砖块放入的决策：放入矮的那边,放入高的那边、不使用这块砖块三种情况。
    dp[a][b]表示：当使用到第a块砖，两座塔的差值为b时，最高的塔的高度。
    **/
    int **dp = new int*[2];
    for(int i = 0; i < 2; i++)
    {
        dp[i] = new int[sum];
        memset(dp[i], 0, sum*sizeof(dp[i]));
    }
    
    int p = 0;
    for(int i = 0; i < h.size(); i++)
    {
        dp[p][h[i]] = max(dp[1-p][h[i]], h[i]);//初始化，当差值为h[i]时的情况仍没有出现过，初始化为h[i]。即之前的砖块都没有使用，把i砖块放入其中一个塔。
        for(int j = 0; j <= sum/2; j++)
        {
            if(dp[1-p][j])
            {
                //不使用i砖的情况，取差值为j时的最大值
                if(dp[p][j] < dp[1-p][j])
                    dp[p][j] = dp[1-p][j];
                
                //放入高的塔
                dp[p][j + h[i]] = max(dp[p][j + h[i]], max(dp[1-p][j + h[i]], dp[1-p][j] + h[i]));
                
                //放入低的塔
                int index = abs(j - h[i]);
                dp[p][index] = max(dp[p][index], max(dp[1-p][index], max(dp[1-p][j] - j + h[i], dp[1-p][j])));
            }
        }
        p = 1 - p;
    }
    
    int ans = -1;
    if(dp[1 - p][0]){
        ans = dp[1 - p][0];
    }
    cout << ans << endl;
   
    return 0;
}





