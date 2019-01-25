/*数组中只出现一次的数字
  
  题目描述：
      一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
 */

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        //用set，遍历有重复的数组就删除，没有重复就插入，最后剩下的两个数就是两个只出现一次的数字。时间复杂度为O(n)
        set<int> save;
        set<int>::iterator it;
        for(int i=0;i<data.size();i++)
        {
            if(save.find(data[i])==save.end())
                save.insert(data[i]);
            else
            {
                it=save.find(data[i]);
                save.erase(it);
            }
        }
        it=save.begin();
        *num1=*it;
        *num2=*(++it);
    }
};
