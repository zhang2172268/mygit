/* 另类加法

   题目描述：
		请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
给定两个int A和B。请返回A＋B的值
 */


class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        if(0 == A)
            return B;
        if(0 == B)
            return A;
        return addAB(A^B, (A&B)<<1);
    }
};
