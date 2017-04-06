/**
给定一个数组a[N]，我们希望构造数组b [N]，其中b[j]=a[0]*a[1]…a[N-1] / a[j]，在构造过程中，不允许使用除法；
要求：
O（1）空间复杂度和O（n）的时间复杂度；
除遍历计数器与a[N] b[N]外，不可使用新的变量（包括栈临时变量、堆空间和全局静态变量等）
虽然不能使用临时变量，但是可以用数组本身的某一个元素，不让用除法，应该想到迭代的用乘法，而且b中每个元素是两部分的乘积
**/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

#define N 5 

void create_array(int a[],int b[])  
{  
    b[0] = 1;  
    for(int i = 1; i < N; i++)  
        b[i] = b[i-1] * a[i-1];  
    b[0] = 1;  
    for(int i = N-1; i > 0; i--)  
    {  
        b[i] = b[i] * b[0];  
        b[0] *= a[i];  
    }
}
  
int main()  
{  
    int a[N] = {2, 3, 4, 5, 6};  
    int b[N];  
    create_array(a, b);  
    for(int i = 0; i < N; i++)  
        printf("%d ", b[i]);  
    return 0;  
}  