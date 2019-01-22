/* 数组中的逆序对

   题目描述：
       
       在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字

数据范围：

	对于%50的数据,size<=10^4

	对于%75的数据,size<=10^5

	对于%100的数据,size<=2*10^5

示例1
    输入:
       1,2,3,4,5,6,7,0
    输出:
       7
 */


class Solution {
public:
    int InversePairs(vector<int> data) {
        int n= data.size();
        long long int result;
        vector<int> temp=data;
        result= merge_sort(data,0,n-1,temp);
        return result%1000000007;
    }

    long long int  merge(vector<int> &data,int start,int mid,int end,vector<int> &temp){
        int i=start,j=mid+1,k=start;
        long cnt=0;   //这里很重要
        while (i<=mid&&j<=end)
        {
            if(data[i]>data[j]){
                temp[k++]=data[j++];cnt+=mid-i+1;
            }
            else{
                temp[k++]=data[i++];
            }
        }
        while (i<=mid)
        {
            temp[k++]=data[i++];
        }
        while (j<=end)
        {
            temp[k++]=data[j++];
        }
        for (int i=start;i<=end;i++)  //这里忘了将临时数组的值还回去，这样每次白排序了
        {
            data[i]=temp[i];
        }
        return cnt;
    }
    long long int merge_sort(vector<int> &data,int start,int end,vector<int> &temp ){
        int mid;
        long cnt=0;  //这里很重要
        if(start==end){
            temp[start]=data[start];
        }
        else{
            mid=(start+end)/2;
            cnt+=merge_sort(data,start,mid,temp);//这里也要加cnt，每个递归的mergeSort的值都要加起来，为防止错误，最好用全局变量
            cnt+=merge_sort(data,mid+1,end,temp);
            cnt+=merge(data,start,mid,end,temp);
        }
        return cnt;
    }
};
