/*53.最大子序和
	
	给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:
	输入: [-2,1,-3,4,-1,2,1,-5,4],
	输出: 6
	解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(0 == nums.size())
            return NULL;
        int res = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum = max(sum+nums[i], nums[i]);
            res = max(sum, res);
        }
        return res;
    }
};
