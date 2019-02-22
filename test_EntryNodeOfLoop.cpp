/* 链表中环的入口结点
 
   题目描述：
       给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null.
 */

/* 思路：
       1.设链表为1,2,3,...,n,...m 其中m指向n，形成环；可知链表长度为m，环长度为m-n+1，环的入口为n；
       2.使得快慢指针均指向头结点，慢指针步长为1，快指针步长为2；两者相遇时，慢指针走了x步，此时块慢指针均指向1+x，即快指针比慢指针多走了一个环的长度，即1+x等于1+2x坐标，所以x等于环的长度m-n+1；
       3.那么，此时快慢指针的位置为1+x=m-n+2，慢指针走到尾节点还需要n-2步，走到环入口，+1，还需要n-1步，若此时将某个节点从头结点走n-1步，则两者同时到达环入口节点。
 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {

		if (!pHead)
			return nullptr;

		ListNode* fastNode = pHead;
		ListNode* slowNode = pHead;

		while (fastNode && fastNode->next)
		{
			fastNode = fastNode->next;
			fastNode = fastNode->next;

			slowNode = slowNode->next;

			if (fastNode == slowNode)
				break;
		}

		if (!fastNode || !fastNode->next)
			return nullptr;

		fastNode = pHead;
		while (fastNode != slowNode)
		{
			fastNode = fastNode->next;
			slowNode = slowNode->next;
		}

		return fastNode;
    }
};
