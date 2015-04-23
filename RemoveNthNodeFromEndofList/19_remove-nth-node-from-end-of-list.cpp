/********************************************************************************** 
* 
* Given a linked list, remove the nth node from the end of list and return its head.
* 
* For example,
* 
*    Given linked list: 1->2->3->4->5, and n = 2.
* 
*    After removing the second node from the end, the linked list becomes 1->2->3->5.
* 
* Note:
* Given n will always be valid.
* Try to do this in one pass.
* 
*               
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
  *设两个指针$p,q$，让$q$先走$n$步，
  *然后$p$和$q$一起走，直到$q$走到尾节点，删除{p->next}即可。
  *这种方法一般在head之前还要设置一个dummy结点，以方便处理n == len的情形。
  */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev, *p;
        ListNode dummy(-1);
        dummy.next = head;
        prev = &dummy;
        p = &dummy;
        
        for(int i = 0; i < n; ++i){
            p = p->next;
        }
        while(p->next){
            p = p->next;
            prev = prev->next;
        }
        ListNode *tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;
        return dummy.next;
    }
};