/**
315. Count of Smaller Numbers After Self
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
**/

//方法1
//BIT，binary indexed tree树状数组
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans = nums;
        unordered_map<int, int> reflect;
        bit_array.resize(len + 1);
        sort(ans.begin(), ans.end());
        for (int i = 0; i < len; ++ i)
            reflect[ans[i]] = i + 1;
        
        for (int i = len - 1; i >= 0; -- i) {
            ans[i] = query(reflect[nums[i]] - 1);
            add(reflect[nums[i]], 1);
        }
        return ans;
    }
    
private:
    vector<int> bit_array;
    inline int lowbit(int pos)
    {
        return pos & -pos;
    }
    void bit_add(int pos, int val)
    {
        long len = bit_array.size();
        while(pos < len)
        {
            bit_array[pos] += val;
            pos += lowbit(pos);
        }
    }
    int query(int pos)
    {
        int ret = 0;
        while(pos > 0)
        {
            ret += bit_array[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
};

//方法2
//BST，二叉搜索树
/**
Every node will maintain a val sum recording the total of number on it's left bottom side, dup counts the duplication. For example, [3, 2, 2, 6, 1], from back to beginning,we would have:

                1(0, 1)
                     \
                     6(3, 1)
                     /
                   2(0, 2)
                       \
                        3(0, 1)
When we try to insert a number, the total number of smaller number would be adding dup and sum of the nodes where we turn right.
for example, if we insert 5, it should be inserted on the way down to the right of 3, the nodes where we turn right is 1(0,1), 2,(0,2), 3(0,1), so the answer should be (0 + 1)+(0 + 2)+ (0 + 1) = 4

if we insert 7, the right-turning nodes are 1(0,1), 6(3,1), so answer should be (0 + 1) + (3 + 1) = 5
**/
class Solution2 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len);
        Node* root = NULL;
        for(int i = len-1; i >= 0; i--)
        {
            root = insert(nums[i], root, ans, i, 0);
        }
        return ans;
    }
    
private:
    struct Node
    {
        Node* left;
        Node* right;
        int val, sum;
        int dup = 1;
        
        Node(int v, int s)
        {
            val = v;
            sum = s;
            left = NULL;
            right = NULL;
        }
    };
    
    Node* insert(int num, Node* node, vector<int> &ans, int i, int preSum)
    {
        if(node == NULL)
        {
            node = new Node(num, 0);
            ans[i] = preSum;
        }else if(node->val == num)
        {
            node->dup++;
            ans[i] = preSum + node->sum;
        }else if(node->val > num)
        {
            node->sum++;
            node->left = insert(num, node->left, ans, i, preSum);
        }else
        {
            node->right = insert(num, node->right, ans, i, preSum + node->dup + node->sum);
        }
        return node;
    }
};