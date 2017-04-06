/**
腾讯2017年实习生编程题目(第三题)
3.有趣的数字
小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？
输入描述:
 输入包含多组测试数据。
 对于每组测试数据：
 N - 本组测试数据有n个数
 a1,a2...an -需要计算的数据
 保证:
 1<=N<=100000,0<=ai<=INT_MAX.
 
输出描述:
对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。
 
输入例子:
6
45 12 45 32 5 6
 
输出例子:
1 2
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;

    while (cin>>n) {
        vector<int> nums(n);
        for (int i=0; i<n; i++) {
            cin>>nums[i];
        }

        int minNum=0, maxNum=0;
        //排序
        sort(nums.begin(), nums.end());

        //最大,看有序数组有几个最小值和几个最大值，相乘即可。
        int m1 = 0, m2 = n-1, a=1, b=1;
        while (nums[m1+1] == nums[m1]) {
            a++;
            m1++;
        }

        while (nums[m2] == nums[m2-1]) {
            b++;
            m2--;
        }
        maxNum = a*b;

        //最小,由于是有序数组，必定是相邻的差值较小，故由排序后的有序数组求出差值最小值。如果差值最小值为0，则算出数组中相等的元素的对数；如果差值最小值不为0，则只需计算有多少个最小值即可。
        int minTemp=nums[n-1];
        for (int i=1; i<n; i++) {
            if (nums[i]-nums[i-1]<minTemp) {
                minTemp = nums[i]-nums[i-1];
            }
        }

        if (minTemp >0) {

            for (int i=1; i<n; i++) {
                if (nums[i]-nums[i-1] == minTemp) {
                    minNum++;
                }
            }

        }else{

            for (int i=1; i<n; i++) {
                int j=i-1;
                while (nums[j]==nums[i] && j>=0) {
                    minNum++;
                    j--;
                }
            }
        }

        cout<<minNum<<" "<<maxNum<<endl;

    }

    return 0;
}