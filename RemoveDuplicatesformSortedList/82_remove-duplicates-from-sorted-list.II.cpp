/********************************************************************************** 
* 
* Given a sorted linked list, delete all nodes that have duplicate numbers, 
* leaving only distinct numbers from the original list.
* 
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
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
        ListNode *deleteDuplicates(ListNode *head) {
            ListNode dummy(-1);
            ListNode* p = &dummy;
            ListNode* prev = head;
            int flag = 0;
            if (head == nullptr || head->next == nullptr) return head;
            for (ListNode* cur = prev->next; prev;){
                if (cur && prev->val == cur->val){
                    delete prev;
                    prev = cur;                                                                                
                    cur = cur->next;
                    flag = 1;
                }
                else if (flag == 1 ){
                    delete prev;
                    prev = cur;
                    if (prev == nullptr) break;
                    cur = cur->next;
                    flag = 0;
                }
                else{
                    p->next = prev;
                    p = p->next;
                    prev = cur;
                    if(cur) cur = cur->next;		
                }

            }
            p->next = nullptr;
            return dummy.next;
        }
};
