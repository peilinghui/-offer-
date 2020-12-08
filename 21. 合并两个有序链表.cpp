21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4



var mergeTwoLists = function(l1, l2) {
    if(l1 === null){
        return l2;
    }
    if(l2 === null){
        return l1;
    }
    if(l1.val < l2.val){
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    }else{
        l2.next = mergeTwoLists(l1, l2.next);
        return l2;
    }
};


迭代
定义头结点
若 l1l1 指向的结点值 << l2l2 指向的结点值，则将 l1l1 链接到头结点的 nextnext 位置
否则将 l2l2 链接到头结点的 nextnext 位置
循环进行，直至 l1l1 或 l2l2 为 NULLNULL
最后，将 l1l1 或 l2l2 中剩下的部分，链接到头结点后面
代码

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(1);
        ListNode* ret = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = l1 == NULL ? l2 : l1;
        return ret->next;
    }
};

递归
编写递归的第一步，应当是明确当前函数应当完成的功能。

函数功能

返回 l1l1 指向的结点和 l2l2 指向的结点中，值较小的结点
并将从下级函数获得的返回值，链接到当前结点尾部
函数结束条件

当 l1l1 为空，或 l2l2 为空，函数结束
返回 l1l1 或 l2l2 中剩下的部分
代码

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
};
