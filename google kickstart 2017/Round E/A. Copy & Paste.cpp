/**
Problem A. Copy & Paste
Problem
You want to create a certain target string S, which consists only of lowercase English letters. You start with an empty string, and you are allowed to perform the following operations:
Add any single lowercase letter to the end of your string.
Copy any substring of your string (that is, all of the characters between some start point in your string and some end point in your string) to the clipboard. Doing this overwrites whatever was in the clipboard before. The clipboard starts off empty.
Add the entire contents of the clipboard to the end of your string. (The contents of the clipboard do not change.)
What is the smallest number of operations needed to create your target string? Note that you must create exactly the target string, with no additional letters.

Input
The first line of the input gives the number of test cases, T. T lines follow. Each line contains the target string S.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number of operations (as described in the problem statement) needed to create the target string.

Limits
S consists only of lowercase English letters in the range a through z.
Small dataset
1 ≤ T ≤ 100.
1 ≤ length of S ≤ 6.
Large dataset
1 ≤ T ≤ 100.
1 ≤ length of S ≤ 100.
Sample


Input 
3
abcabab
aaaaaaaaaaa
vnsdmvnsnsdmkvdmkvnsdmk

Output
Case #1: 6
Case #2: 7
Case #3: 15

The optimal solution for Sample Case #1 is:
Type a.
Type b.
Type c.
Copy ab to the clipboard.
Paste ab at the end of the string.
Paste ab at the end of the string.
The optimal solution for Sample Case #2 is:
Type a.
Type a.
Type a.
Copy aaa to the clipboard.
Paste aaa at the end of the string.
Copy aaaaa to the clipboard.
Paste aaaaa at the end of the string.
**/
/**
思路：动态规划
     dp[i][j][k]:表示在已经生成了i位置及其之前的所有字符串，并且clipboard内函数从j到k的字符串时，使用的最少步数。
**/
#include "bits/stdc++.h"
using namespace std;

int dp[305][305][305];
int solve(string &s){
    if(s.size() <= 5)
        return s.size();

    memset(dp, 127/3, sizeof dp);
    int len = s.size();
    s = "#" + s;
    dp[0][0][0] = 0;
    for(int i = 0; i <= len; i++)
    {
        //找出生成到第i位时，使用的最少步数，无论clipboard是什么状态
        int curr_best = dp[i][0][0];
        for(int j = 1; j <= i; j++)
            for(int k = 1; j+k-1 <= i; k++)
                curr_best = min(curr_best, dp[i][j][k]);
        //生成目标达到，返回
        if(i == len)
        {
            return curr_best;
        }
        //在已生成第i位的基础上，
        //比较基于最少步数+1（复制到clipboard操作）和其他clipboard状态下最少步数，更新每个状态的最少步数
        for(int j = 1; j <= i; j++)
            for(int k = 1; j+k-1 <= i; k++)
                dp[i][j][k] = min(dp[i][j][k], curr_best + 1);

        //开始生成下一步
        //基于clipboard的状态，添加一步，作为下一个生成位置各种clipboard状态的初始值
        dp[i+1][0][0] = min(dp[i+1][0][0], dp[i][0][0] + 1);
        for(int j = 1; j <= i; j++)
            for(int k = 1; j+k-1 <= i; k++)
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k] + 1);

        //基于使用clipboard中的值来复制生成下几个位置，其状态更新。
        for(int j = 0; j <= i; j++)
        {
            int index = 0;
            while(s[i+1+index] == s[j+index])
                index++;
            for(int k = 0; k <= index; k++)
            {
                dp[i+k][j][k] = min(dp[i+k][j][k], dp[i][j][k] + 1);
            }
        }
    }
}

int main(){
    freopen("E:\\google kickstart 2017 round E\\A-large-practice.in", "r", stdin);
    freopen("E:\\google kickstart 2017 round E\\A-large-practice", "w", stdout);
    int N;
    cin >> N;
    for(int cas = 1; cas <= N; cas++){
        string s;
        cin >> s;
        int ret = solve(s);
        cout << "Case #" << cas << ": " << ret << endl;
    }
    return 0;
}
