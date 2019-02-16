/* 二叉搜索树与双向链表

   题目描述：
       输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
 */


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr){
            return nullptr;
        }
        //inorder
        stack<TreeNode*> s;
        TreeNode* pre = nullptr;
        TreeNode* root = pre;
        bool isFirst = true;
        while(!s.empty() || pRootOfTree != nullptr){
            while(pRootOfTree != nullptr){
                s.push(pRootOfTree);
                pRootOfTree = pRootOfTree -> left;

            }
            if(!s.empty()){
               pRootOfTree = s.top();
               s.pop();
               if(isFirst){
                   isFirst = false;
                   pre = pRootOfTree;
                   root = pre;

                }
                else{//举例子，最左边的最右边的节点都是叶子节点，左右都是指向null，所以不需要特殊处理
                    pre -> right = pRootOfTree;
                    pRootOfTree -> left = pre;
                    pre = pRootOfTree;
                }
               pRootOfTree = pRootOfTree -> right;
            }
        }

        return root;
    }
};
