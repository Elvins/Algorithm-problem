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
        //�����ݴ��Ѿ�������������
        map<int, int> numsMap;
        map<int, int>::iterator l_it;
        for(int i = 0; i < len; ++i){
            //Ѱ��MAP���Ƿ��ж�Ӧ�𰸵�����
            l_it=numsMap.find(target - nums[i]);
            if(l_it != numsMap.end()){
                //���У�������
                result.push_back(numsMap[target - nums[i]]);
                result.push_back(i);
                break;
            }
            numsMap[nums[i]] = i;
        }
        return result;
    }
};