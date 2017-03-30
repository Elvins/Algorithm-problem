/**
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
**/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> result;
        //用于暂存已经搜索过的数字
        map<int, int> numsMap;
        map<int, int>::iterator l_it;
        for(int i = 0; i < len; ++i){
            //寻找MAP中是否有对应答案的数据
            l_it=numsMap.find(target - nums[i]);
            if(l_it != numsMap.end()){
                //如有，输出结果
                result.push_back(numsMap[target - nums[i]]);
                result.push_back(i);
                break;
            }
            numsMap[nums[i]] = i;
        }
        return result;
    }
};