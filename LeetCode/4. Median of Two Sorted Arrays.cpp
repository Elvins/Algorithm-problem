/**
4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
**/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;  
        if ((total % 2) == 1)  
            return findKthSortedArrays(nums1, 0, m, nums2, 0, n, total / 2 + 1);  
        else  
            return (findKthSortedArrays(nums1, 0, m, nums2, 0, n, total / 2) + findKthSortedArrays(nums1, 0, m, nums2, 0, n, total / 2 + 1)) / 2;  
    }
    
private:
    //寻找两个数排序组合并后第K个数
    //a:向量A的开始位置，m：向量A从a位置开始到末尾的有效长度
    //b:向量B的开始位置，n：向量B从b位置开始到末尾的有效长度
    //k:寻找的第K个数
    double findKthSortedArrays(vector<int>& A, int a, int m, vector<int>& B, int b, int n, int k)
    {
         //默认数组A的长度始终比数组B的长度小
        if (m > n)
            return findKthSortedArrays(B, b, n, A, a, m, k);
        if (m == 0)
            return B[b + k - 1];
        if (k == 1)
            return min(A[a + 0], B[b + 0]);
        //将K分为两部分
        int pa = min(k / 2, m), pb = k - pa;
        if (A[a + pa - 1] < B[b + pb - 1])
            return findKthSortedArrays(A, a + pa, m - pa, B, b, n, k - pa);
        else if (A[a + pa - 1] > B[b + pb - 1])
            return findKthSortedArrays(A, a, m, B, b + pb, n - pb, k - pb);
        else
            return A[a + pa - 1];
    }
};