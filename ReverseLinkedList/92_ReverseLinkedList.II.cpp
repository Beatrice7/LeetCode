/********************************************************************************** 
* 
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
* 
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
* 
* return 1->4->3->2->5->NULL.
* 
* Note:
* Given m, n satisfy the following condition:
* 1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        ListNode* prev = &dummy;
        prev->next = head;
        
        for(int i = 1; i < m; ++i){
            prev = prev->next;
        }
        ListNode* start = prev->next;
        ListNode* cur = start->next;
        //头插法，一次插在第m个元素之前，需要三个指针
        for(int i = m; m < n; ++m){
            start->next = cur->next;
            cur->next = prev->next;/*这步要在下一步之前，刚开始错写成cur->next = start->next了*/
            prev->next= cur;
            //start->next = cur;
            cur = start->next;
        }
        return dummy.next;
        
    }
};
