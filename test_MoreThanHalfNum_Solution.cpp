/* 数组中次数超过一半的数字

   题目描述：
       数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 */

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    //其实这个题目很简单，直接排一次序，然后计算中位数的个数，如果中位数个数大于总数
    //的1/2，那么就返回mid，否则返回0
      sort(numbers.begin(),numbers.end());
      int mid = numbers[numbers.size()/2];
      int s = 0;
      for(int i=0;i<numbers.size();++i)
      {
          if(mid==numbers[i])
               s++;
      }
       if(s>numbers.size()/2)
           return mid;
        else
            return 0;
    }
};
