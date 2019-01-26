/*和为S的两个数字
  
  题目描述：
      输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

  输出描述:
      对应每个测试案例，输出两个数，小的先输出。
 */


class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        int n = array.size();
        if(n<=0)
            return result;
        int start = 0;
        int end = n-1;

        while(start<end)
        {
            int curSum = array[start] + array[end];
            if(curSum == sum)
            {
                result.push_back(array[start]);
                result.push_back(array[end]);
                break;
            }
            else if(curSum < sum)
                start ++;
            else if(curSum > sum)
                end --;
        }
        return result;
    }
};
