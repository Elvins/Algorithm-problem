/**
题目2 : Tree Restoration
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
There is a tree of N nodes which are numbered from 1 to N. Unfortunately, its edges are missing so we don't know how the nodes are connected. Instead we know:  

1. Which nodes are leaves  

2. The distance (number of edges) between any pair of leaves

3. The depth of every node (the root's depth is 1)

4. For the nodes on the same level, their order from left to right

Can you restore the tree's edges with these information? Note if node u is on the left of node v, u's parent should not be on the right of v's parent.

tree-restoration.png

输入
The first line contains three integers N, M and K. N is the number of nodes. M is the depth of the tree. K is the number of leaves.

The second line contains M integers A1, A2, ... AM. Ai represents the number of nodes of depth i.

Then M lines follow. The ith of the M lines contains Ai numbers which are the nodes of depth i from left to right.  

The (M+3)-th line contains K numbers L1, L2, ... LK, indicating the leaves.

Then a K × K matrix D follows. Dij represents the distance between Li and Lj.

1 ≤ N ≤ 100

输出
For every node from 1 to N output its parent. Output 0 for the root's parent.

样例输入
8 3 5
1 3 4
1
2 3 4
5 6 7 8
3 5 6 7 8
0 3 3 3 3
3 0 2 4 4
3 2 0 4 4
3 4 4 0 2
3 4 4 2 0
样例输出
0 1 1 1 2 2 4 4
**/

#include <bits/stdc++.h>
using namespace std;

struct LeafChild
{
    int child;
    int generation;
    LeafChild(int c, int g)
    {
        child = c;
        generation = g;
    }
};

int main()
{
    int L[105][105];
    memset(L, 0, sizeof(L));
    int N, M, K;
    vector<int> A;
    vector<vector<int> > T;
    map<int, int>leaves;
    map<int, LeafChild*>leaf_child;
    
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    for(int i = 0; i < M; i++)
    {
        vector<int> v;
        for(int j = 0; j < A[i]; j++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        T.push_back(v);
    }
    for(int i = 0; i < K; i++)
    {
        int tmp;
        cin >> tmp;
        leaves[tmp] = i + 1;
    }
    for(int i = 1; i <= K; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            cin >> L[i][j];
        }
    }
    
    vector<int> ans;
    for(int i = M-1; i > 0; i--)
    {
        vector<int> temp;
        int parent = 0;
        while(leaves.find(T[i-1][parent]) != leaves.end())
        {
            parent++;
        }
        for(int j = 0; j < A[i]; j++)
        {
            if(j == 0)
            {
                temp.push_back(T[i-1][parent]);
                if(leaves.find(T[i][j]) != leaves.end()){
                    leaf_child[T[i-1][parent]] = new LeafChild(T[i][j], 1);
                }else
                {
                    LeafChild *curLeafChild = leaf_child[T[i][j]];
                    leaf_child[T[i-1][parent]] = new LeafChild(curLeafChild->child, curLeafChild->generation + 1);
                }
            }else
            {
                if(leaves.find(T[i][j-1]) != leaves.end() && leaves.find(T[i][j]) != leaves.end())
                {
                    if(L[leaves[T[i][j-1]]][leaves[T[i][j]]] == 2)
                    {
                        temp.push_back(T[i-1][parent]);
                    }else
                    {
                        parent++;
                        while(leaves.find(T[i-1][parent]) != leaves.end())
                        {
                            parent++;
                        }
                        temp.push_back(T[i-1][parent]);
                        leaf_child[T[i-1][parent]] = new LeafChild(T[i][j], 1);
                    }
                }else if(leaves.find(T[i][j-1]) == leaves.end() && leaves.find(T[i][j]) != leaves.end())
                {
                    LeafChild *preLeafChild = leaf_child[T[i][j-1]];
                    if(L[leaves[preLeafChild->child]][leaves[T[i][j]]] - preLeafChild->generation == 2)
                    {
                        temp.push_back(T[i-1][parent]);
                    }else
                    {
                        parent++;
                        while(leaves.find(T[i-1][parent]) != leaves.end())
                        {
                            parent++;
                        }
                        temp.push_back(T[i-1][parent]);
                        leaf_child[T[i-1][parent]] = new LeafChild(T[i][j], 1);
                    }
                    
                }else if(leaves.find(T[i][j-1]) != leaves.end() && leaves.find(T[i][j]) == leaves.end())
                {
                    LeafChild *curLeafChild = leaf_child[T[i][j]];
                    if(L[leaves[T[i][j-1]]][leaves[curLeafChild->child]] - curLeafChild->generation == 2)
                    {
                        temp.push_back(T[i-1][parent]);
                    }else
                    {
                        parent++;
                        while(leaves.find(T[i-1][parent]) != leaves.end())
                        {
                            parent++;
                        }
                        temp.push_back(T[i-1][parent]);
                        leaf_child[T[i-1][parent]] = new LeafChild(curLeafChild->child, curLeafChild->generation + 1);
                    }
                }else
                {
                    LeafChild *preLeafChild = leaf_child[T[i][j-1]];
                    LeafChild *curLeafChild = leaf_child[T[i][j]];
                    if(L[leaves[preLeafChild->child]][leaves[curLeafChild->child]] - preLeafChild->generation - curLeafChild->generation == 2)
                    {
                        temp.push_back(T[i-1][parent]);
                    }else
                    {
                        parent++;
                        while(leaves.find(T[i-1][parent]) != leaves.end())
                        {
                            parent++;
                        }
                        temp.push_back(T[i-1][parent]);
                        leaf_child[T[i-1][parent]] = new LeafChild(curLeafChild->child, curLeafChild->generation + 1);
                    }
                }
            }
        }
        for(int k = temp.size()-1; k >= 0; k--)
        {
            ans.push_back(temp[k]);
        }
    }
    ans.push_back(0);
    
    for(int i = N-1; i >= 0; i--)
    {
        if(i != N-1)
            cout << " ";
        cout << ans[i];
    }
    
    return 0;
}