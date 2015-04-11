
/********************************************************************************** 
* 
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode head(0);
        ListNode *res = &head;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carry = 0;
        int value = 0;
        while(p1 != nullptr || p2 != nullptr){
            //if (p1 == nullptr) p1->val = 0;
		    //if (p2 == nullptr) p2->val = 0;
		    /*错误原因：如当p2已经为空时，p2->val就无效了*/
            int v1 = (p1 != nullptr) ? p1->val : 0;
		    int v2 = (p2 != nullptr) ? p2->val : 0;
		    value = (v1 + v2 + carry) % 10;
		    carry = (v1 + v2 + carry) / 10;
            res->next = new ListNode(value);
            res = res->next;
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
        }
        if(carry > 0) res->next = new ListNode(carry);
        return head.next;
    }
};