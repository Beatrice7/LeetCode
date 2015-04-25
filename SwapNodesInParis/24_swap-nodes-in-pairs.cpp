/********************************************************************************** 
* 
* Given a linked list, swap every two adjacent nodes and return its head.
* 
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* 
* Your algorithm should use only constant space. You may not modify the values in the list, 
* only nodes itself can be changed.
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;
        
        for(ListNode* prev = &dummy, *cur = prev->next, *nextp = cur->next;
            nextp;
            prev = cur, cur = cur->next, nextp = cur ? cur->next : nullptr)//如果cur已经为空了，那么没有cur->next;直接把nextp赋空
            {
                cur->next = nextp->next;
                prev->next = nextp;
                nextp->next = cur;
            }
        
        return dummy.next;
    }
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head;
        while(p && p->next){
            swap(p->val, p->next->val);
            p = p->next->next;
        }
        return head;
    }
};

