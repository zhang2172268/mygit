/*扑克牌大小
题目描述
	扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:) 
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

基本规则：
（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。

答案提示：
（1）除了炸弹和对王之外，其他必须同类型比较。
（2）输入已经保证合法性，不用检查输入是否是合法的牌。
（3）输入的顺子已经经过从小到大排序，因此不用再排序了.
输入描述:
	输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如4 4 4 4-joker JOKER。
输出描述:
	输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。

示例1
	输入4 4 4 4-joker JOKER
	输出joker JOKER
*/



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    string line;
    while(getline(cin, line)){
        //如果有两王直接输出，两王最大
        if(line.find('joker JOKER') != -1)//注意此处避免find找到返回下标是0
            cout << "joker JOKER" << endl;
        //分为两手牌
        else{
            int dash = line.find('-');//找到这个-是分成两手牌的标志
            //分为两手牌
            string car1 = line.substr(0, dash);
            string car2 = line.substr(dash+1);
            
            //获取牌长度
            int c1 = count(car1.begin(), car1.end(), ' ');
            int c2 = count(car2.begin(), car2.end(), ' ');
            
            //拿到第一个空格分隔的牌
            string first1 = car1.substr(0, car1.find(' '));
            string first2 = car2.substr(0, car2.find(' '));
            
            string str = "345678910JQKA2jokerJOKER";
            
            
            if(c1 == c2){
                //判断两牌长度相等，那边首元素大就输出
                if(str.find(first1) > str.find(first2))
                    cout << car1 << endl;
                else
                    cout << car2 << endl;
            }
            else{
                //两边牌长度不等，即类型不同
                if(c1 == 3)//注意此处为炸弹，下标是从0开始的
                    cout << car1 << endl;
                else if(c2 == 3)
                    cout << car2 << endl;
                else
                    cout << "ERROR" << endl;
            }
        }
    }
    return 0;
}