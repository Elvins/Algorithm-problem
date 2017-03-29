/**
腾讯2017年实习生编程题目(第二题)
小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
你能帮帮小Q吗？
 
输入描述:
 
输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
  
 
输出描述:
 
对于每组数据，输出移位后的字符串。
 
输入例子:
AkleBiCeilD
 
输出例子:
kleieilABCD
**/

#include<iostream>  
#include<string>  
using namespace std;  
  
int main()  
{  
     string s;    
     while(cin>>s)  
     {  
       int n = s.size();  
       if(n<=1)   
       {  
          cout<<s<<endl;  
           return 0;  
       }  
       int lastUp = n-1;  
       for(int i=n-1;i>=0;i--)  
       {  
          if(isupper(s[i]))  
          {  
              int step = lastUp-i;  
              int temp = s[i];  
              for(int j=i+1;j<=lastUp;j++)//平移一位   
              {  
                 s[j-1] = s[j];  
              }  
              s[lastUp] = temp;  
              lastUp--;  
          }  
       }  
       cout<<s<<endl;  
     }  
      return 0;  
}  