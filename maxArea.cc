/*11.盛最多水的容器

	给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
	在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
	找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

	图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，
	容器能够容纳水（表示为蓝色部分）的最大值为 49。

 示例:
	输入: [1,8,6,2,5,4,8,3,7]
	输出: 49
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        /*暴力分解法；超时
        int ret = 0;
        for(int i = 0; i < height.size(); ++i){
            for(int j = i+1; j < height.size(); ++j){
                int temp1 = min(height[i], height[j]);
                int temp2 = temp1 *(j-i);
                ret = max(ret, temp2);
            }
        }
        return ret;
        */
        
        //双指针，将容量小的指针向数组内部移动
        int left = 0;
        int right = height.size()-1;
        int ret = 0;
        while(left < right){
            int temp1 = min(height[left], height[right]);
            int temp2 = temp1 * (right-left);
            ret = max(ret, temp2);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return ret;
    }
};