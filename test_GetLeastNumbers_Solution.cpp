/* 最小的k个数

   题目描述
       输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
 */


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int in_size = input.size();
        for (int i = 0; i < in_size; ++i)
        {
            for (int j = i; j < in_size; ++j)
            {
                if (input[i]>input[j])
                {
                    swap(input[i], input[j]);
                }
            }
        }

        vector<int> result = {};
        if (k <= in_size)
        {
            for (int i = 0; i < k; ++i)
            {
                result.push_back(input[i]);
            }
            return result;
        }
        else
            return result;
    }
};
