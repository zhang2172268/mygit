/* 机器人的运动范围
 
   题目描述：
       地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 */

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int ** mark = new int * [rows]; //记录是否已经走过
        for(int i = 0; i < rows; ++i){
            mark[i] = new int[cols];
        }

        return DFS(0, 0, rows, cols, mark, threshold);
    }

private:

    int DFS(int x, int y, int rows, int cols, int** mark, int threshold){
        if(x < 0 || y < 0 || x >= rows || y >= cols || mark[x][y] == 1 || numOfSum(x)+numOfSum(y) > threshold){
            return 0;
        }
        mark[x][y] = 1;
        return DFS(x+1, y, rows, cols, mark, threshold) + DFS(x-1, y, rows, cols, mark, threshold) + DFS(x, y+1, rows, cols, mark, threshold) + DFS(x, y-1, rows, cols, mark, threshold) + 1;
    }

    int numOfSum(int x){
        int sum = 0;
        while(x){
            sum += x%10;
            x /= 10;
        }

        return sum;
    }
};
