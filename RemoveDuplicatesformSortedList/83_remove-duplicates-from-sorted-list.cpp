/********************************************************************************** 
* 
* Given a sorted linked list, delete all duplicates such that each element appear only once.
* 
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
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
        if(head == nullptr) return head;
        ListNode *prev = head;
        for(ListNode* cur = head->next; cur != nullptr; cur = cur->next){
            if(cur->val == prev->val){
                //cur = cur->next;
                prev->next = cur->next;
                //这里是要删除掉多余的数，不是直接挪动指针！认真审题啊！
                delete cur;
            }else{
                prev = cur;
            }
            
        }
        return head;
        
    }
};