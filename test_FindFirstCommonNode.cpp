/* 两个链表的第一个公共结点
   
   题目描述：
       输入两个链表，找出它们的第一个公共结点。
 */
  

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        /*
        //方法1：扔进vector倒着看
       vector<ListNode*>a,b;
        ListNode* p1=pHead1;
        ListNode* p2=pHead2;
        while(pHead1){
            a.push_back(pHead1);
            pHead1=pHead1->next;
        }
        while(pHead2){
            b.push_back(pHead2);
            pHead2=pHead2->next;
        }
        while(!a.empty()&&!b.empty()&&a.back()==b.back()){
            a.pop_back();
            b.pop_back();
        }
        if(a.empty())
            return p1;
        if(b.empty())
            return p2;
        return a.back()->next;
        */

        //方法2：
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};
