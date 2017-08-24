/**
15. 3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
**/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        // 枚举第一个加数，注意确保不存在重复情况
        for (int i = 0; i < nums.size(); i++) 
            if (i == 0 || nums[i] != nums[i - 1]) {
            // 按照2sum的双指针方法来进行计算
                int l = i + 1, r = nums.size() - 1;
                while (l < r) {
                    // 右边界左移
                    while (l < r && nums[i] + nums[l] + nums[r] > 0) 
                        r--;
                    if (l < r && nums[i] + nums[l] + nums[r] == 0) {
                        // 添加一组答案
                        vector<int> triplet(3);
                        triplet[0] = nums[i]; triplet[1] = nums[l]; triplet[2] = nums[r];
                        ret.push_back(triplet);
                        while (l < r && nums[l] == triplet[1]) 
                            l++;
                    }else{
                        // 左边界右移
                        l++;
                    }
                }
            }
        // 返回答案
        return ret;
    }
};
