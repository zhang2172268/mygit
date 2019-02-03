/* 数组中重复的数字
 
   题目描述：
       在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
 */


#include<iostream>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication)
    {
        int i,j,temp;
        for(i = 0; i < length - 1; i ++)
        {
            for(j = i+1; j < length; j ++)
            {
                if(numbers[i]>numbers[j])
                {
                    temp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
                }
            }
        }

        temp = 0;
        for(i = 0; i < length - 1; i ++)
        {
            if(numbers[i] == numbers[i+1])
            {
                temp = 1;
                *duplication = numbers[i];
                break;
            }
        }

        if(temp){
            return true;
        }else{
            return false;
        }
    }
};

int main()
{
    Solution ss;
    int a[] = {2, 1, 3, 1, 4};
    int length = 5;
    int dup = 0;

    if(ss.duplicate(a, length, &dup)){
        cout<<"Yes "<<dup<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
