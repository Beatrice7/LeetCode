/********************************************************************************** 
* 
* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
* 
* Follow up:
* Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow, *fast, *slow2;
        slow = fast = slow2 = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        
        if(fast == nullptr || fast->next == nullptr) return NULL;
        
        while(slow2 != slow){
            slow2 = slow2->next;
            slow = slow->next;
        }
        
        return slow2;
    }
};

