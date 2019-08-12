/*MP3光标位置

题目描述
	MP3 Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，
	用户要通过上下键才能浏览所有的歌曲。为了简化处理，假设每屏只能显示4首歌曲，
	光标初始的位置为第1首歌。

	现在要实现通过上下键控制光标移动来浏览歌曲列表，控制逻辑如下：
	歌曲总数<=4的时候，不需要翻页，只是挪动光标位置。
	光标在第一首歌曲上时，按Up键光标挪到最后一首歌曲；光标在最后一首歌曲时，按Down键光标挪到第一首歌曲。
	其他情况下用户按Up键，光标挪到上一首歌曲；用户按Down键，光标挪到下一首歌曲。



  2. 歌曲总数大于4的时候（以一共有10首歌为例）：
	特殊翻页：屏幕显示的是第一页（即显示第1 – 4首）时，光标在第一首歌曲上，
	用户按Up键后，屏幕要显示最后一页（即显示第7-10首歌），同时光标放到最后一首歌上。同样的，屏幕显示最后一页时，光标在最后一首歌曲上，用户按Down键，屏幕要显示第一页，光标挪到第一首歌上。
	
	一般翻页：屏幕显示的不是第一页时，光标在当前屏幕显示的第一首歌曲时，用户按Up键后，
	屏幕从当前歌曲的上一首开始显示，光标也挪到上一首歌曲。光标当前屏幕的最后一首歌时的Down键处理也类似。
	其他情况，不用翻页，只是挪动光标就行。

 

输入描述:
输入说明：
1 输入歌曲数量
2 输入命令 U或者D

输出描述:
输出说明
1 输出当前列表
2 输出当前选中歌曲

示例1
输入
10
UUUU

输出
7 8 9 10
7
*/


#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;//歌曲数量
    string order;//命令
    while(cin >> n >> order){
        int num =1; //当前歌曲位于第几首位置
        int first = 1;//当前页第一首歌曲编号
        
        if(n <= 4){
            for(int i = 0; i < order.size(); ++i){
                if(num == 1 && order[i] == 'U')
                    num = n;
                else if(num == n && order[i] == 'D')
                    num = 1;
                else if(order[i] == 'U')
                    num--;
                else
                    num++;
            }
            
            for(int i = 1; i < n; ++i)
                cout << i << " ";
            cout << n << endl;
            cout << num << endl;
        }
        
        else{
            for(int i = 0; i < order.size(); ++i){
                if(first == 1 && num == 1 && order[i] == 'U'){
                    first = n-3;
                    num = n;
                }
                else if(first == n-3 && num == n && order[i]== 'D'){
                    first = 1;
                    num = 1;
                }
                else if(first != 1 && num == first && order[i] =='U'){
                    first--;
                    num--;
                }
                else if(first != n-3 && num ==first+3 && order[i] == 'D'){
                    first++;
                    num++;
                }
                else if(order[i] == 'U')
                    num--;
                else
                    num++;
            }
            
            for(int i = first; i < first+3; ++i )
                cout << i << " ";
            cout << first+3 << endl;
            cout << num << endl;
        }
    }
    return 0;
}