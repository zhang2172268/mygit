/*数字在排列数组中出现的次数

  题目描述：
      统计一个数字在排列数组中出现的次数。
 */


class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) 
            return 0;
        int count=0;
        for(int i=0;i<data.size();++i){
            if(k==data[i]) ++count;
        }
        return count;
    }
};
