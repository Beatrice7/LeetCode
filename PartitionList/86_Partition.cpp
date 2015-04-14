/********************************************************************************** 
* 
* Given a linked list and a value x, partition it such that all nodes less than x come 
* before nodes greater than or equal to x.
* 
* You should preserve the original relative order of the nodes in each of the two partitions.
* 
* For example,
* Given 1->4->3->2->5->2 and x = 3,
* return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        ListNode less_dummy(-1);
        ListNode larger_dummy(-1);
        ListNode* less_cur = &less_dummy;
        ListNode* larger_cur = &larger_dummy;
        ListNode* cur = head;
        while(cur != nullptr){
            if(cur->val < x){
                less_cur->next = cur;
                less_cur = cur;
            }else{
                larger_cur->next = cur;
                larger_cur = cur;
            }
            cur = cur->next;
        }
        //末尾要加上空指针！！
        larger_cur->next = nullptr;
        less_cur->next = larger_dummy.next;
        return less_dummy.next;
    }
};