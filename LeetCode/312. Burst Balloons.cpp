/**
312. Burst Balloons
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:
Given [3, 1, 5, 8]
Return 167
   nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
   
思路：
dp[1][n]:把[1, n]区间里面的气球全部戳掉后得到的最高分数
shoot_num: 在[1, n]区间内最后一个戳掉的气球index
状态转移方程：
dp[l][r] = max(dp[l][r], nums[l-1]*nums[shoot_num]*nums[r+1] + (dp[l][shoot_num-1] + dp[shoot_num+1][r]) | l <= shoot_num <= r )
**/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int total_len = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for(int len = 1; len <= total_len; len++)
        {
            for(int left = 1; left <= total_len-len+1; left++)
            {
                int right = left + len - 1;
                for(int shoot_num = left; shoot_num <= right; shoot_num++)
                {
                    int score = nums[left-1] * nums[shoot_num] * nums[right+1] + (dp[left][shoot_num-1] + dp[shoot_num+1][right]);
                    if(score > dp[left][right])
                        dp[left][right] = score;
                }
                //cout << "dp[" << left << "][" << right << "] = " << dp[left][right] << endl;
            }
        }
        return dp[1][total_len]; 
    }
};
