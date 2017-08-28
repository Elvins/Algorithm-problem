/**
Problem B. Trapezoid Counting
Problem
In this problem, we will consider a trapezoid to be a convex quadrilateral with exactly one pair of parallel sides. If the lengths of the two non-parallel sides are equal, we say the trapezoid is isosceles.
You have some wooden sticks of various lengths, and you need to pick exactly four of them to form the four sides of an isosceles trapezoid. How many different sets of four sticks will allow this? Even if two sticks have the same length, they are considered to be different sticks. Sticks could not be bended and broke into parts.

Input
The first line of the input gives the number of test cases, T. T test cases follow; each consists of two lines. The first line consists of one integer N, the number of sticks. The second line consists of N integers; the i-th of these, Li, represents the length of the i-th stick.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1), and y is the number of different sets of four sticks that can form an isosceles trapezoid, as described above.

Limits
1 ≤ T ≤ 100.
1 ≤ Li ≤ 109.
Small dataset

1 ≤ N ≤ 50.
Large dataset

1 ≤ N ≤ 5000.
Sample

Input 
5
5
2 3 3 4 3
4
1 5 3 1
4
2 2 3 3
4
999999998 999999999 999999999 1000000000
9
3 4 1 4 2 5 3 1 3

Output
Case #1: 5
Case #2: 0
Case #3: 0
Case #4: 1
Case #5: 73

In Sample Case #1, there are five ways to choose four out of the five given sticks, and any one of those five sets of four sticks can be used to form an isosceles trapezoid. 
In Sample Case #2, note that the set {1, 1, 3, 5} cannot form an isosceles trapezoid, even though two of its sticks are of equal length.
In Sample Case #3, note that the set {2, 2, 3, 3} can form a rectangle, but in this problem, a rectangle is not considered to be an isosceles trapezoid.
**/
/**
思路：
一个set存已经出现过的数字（去重），作为上下低。
一个map存出现次数大于等于2的数字，作为腰。
分情况：
  1. 上下底和腰不等：看腰的个数是否大于2；(1)等于2的result+1;(2)大于二的算组合数。
  2. 上下底存在一个和腰相等，判断腰是否大于三，大于三的算组合数。
最后看上下底是否出现多次，result * 相应个数。
**/

#include "bits/stdc++.h"
using namespace std;

long long solve(vector<int> &nums){
    unordered_set<int> uset;
    map<int, int> nmap;
    for(int item: nums){
        if(uset.count(item)){
            if(nmap.count(item)){
                nmap[item]++;
            }else{
                nmap[item] = 2;
            }
        }else{
            uset.insert(item);
        }
    }

    long long ret = 0;
    for(unordered_set<int>::iterator it = uset.begin(); it != uset.end(); it++){
        int a = *it;
        unordered_set<int>::iterator bit = it;
        for(; bit != uset.end(); bit++) {
            int b = *bit;
            int temp = abs(a - b) / 2;
            if(a == b)
                continue;
            map<int, int>::iterator mit = nmap.upper_bound(temp);
            for (; mit != nmap.end(); mit++) {
                int c = mit->first;
                int count = mit->second;
                long long subRet = 0;
                if (c <= temp) {
                    //cout << "continue. a:" <<a <<" b:" << b <<" c:" << c << endl;
                    continue;
                }
                if (count == 2) {
                    if (c == a || c == b) {
                        continue;
                    }
                    subRet += 1;
                } else {
                    if (c == a || c == b) {
                        subRet += count * (count - 1) * (count - 2) / 6;
                    } else {
                        subRet += count * (count - 1) / 2;
                    }
                }
                if(nmap.count(a) && c != a){
                    subRet *= nmap[a];
                }
                if(nmap.count(b) && c != b){
                    subRet *= nmap[b];
                }
                ret += subRet;
                //cout << "round. a:" <<a <<" b:" << b <<" c:" << c << " subRet:" << subRet << endl;
            }

        }

    }
    return ret;
}

int main(){
    freopen("E:\\B-large-practice.in", "r", stdin);
    freopen("E:\\B-large-practice.out", "w", stdout);
    int N;
    cin >> N;
    for(int cas = 1; cas <= N; cas++){
        int len;
        cin >> len;
        vector<int> v;
        while(len--){
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        long long ret = solve(v);
        cout << "Case #" << cas << ": " << ret << endl;
    }
    return 0;
}