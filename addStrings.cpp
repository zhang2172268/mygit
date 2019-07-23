/*415.字符串相加
	
	给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：
	num1 和num2 的长度都小于 5100.
	num1 和num2 都只包含数字 0-9.
	num1 和num2 都不包含任何前导零。
	你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.size()-1;
        int n2=num2.size()-1;
        int temp = 0;
        string ret ="";
        while(n1>=0 || n2>= 0 || temp !=0){
            if(n1>=0)
                temp += num1[n1--] - '0';
            if(n2>=0)
                temp += num2[n2--] - '0';
            ret += temp%10 + '0';
            temp /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};