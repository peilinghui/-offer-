83. 删除排序链表中的重复元素
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3




删除排序链表中的重复元素
陈乐乐
发布于 2019-05-10
7.9k
解法1：双指针法

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p=head;//慢指针
        ListNode* q=head->next;//快指针
        while(p->next!=NULL)
        {
            if(p->val==q->val)//找到重复元素
            {
                if(q->next==NULL)//快指针后面若没有元素直接剔除
                    p->next=NULL;
                else//快指针后有元素
                {
                    p->next=q->next;
                    q=q->next;
                }
            }
            else //元素不相等
            {
                p=p->next;
                q=q->next;
            }
        }
        return head;
    }
};
解法2：直接法（一个指针操作）

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* p=head;
        while(p->next!=NULL&&p!=NULL)
        {
            if(p->val == p->next->val)
            {
                p->next=p->next->next;
            }
            else 
                p=p->next;
        }
        return head;
    }
};
解法3：递归法

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)
            return head;
        head->next=deleteDuplicates(head->next);
        if(head->val==head->next->val) head=head->next;
        return head;
    }
};
递归套路解决链表问题：
找终止条件：当head指向链表只剩一个元素的时候，自然是不可能重复的，因此return
想想应该返回什么值：应该返回的自然是已经去重的链表的头节点
每一步要做什么：宏观上考虑，此时head.next已经指向一个去重的链表了，而根据第二步，我应该返回一个去重的链表的头节点。因此这一步应该做的是判断当前的head和head.next是否相等，如果相等则说明重了，返回head.next，否则返回head


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *prev = head, *curr = head -> next;
        while(prev && prev->next)
        {
            if(curr->val == prev->val)
            {
                prev -> next = curr -> next;
                curr = curr -> next;
            }
            else prev = prev -> next; // 注意，题目给的是已排好序的链表，所以一旦curr和prev的值不等，那么后面全部都不会出现和当前prev的值相等的元素了，所以prev可以往后移动一位
        }
        return head;
    }
};


