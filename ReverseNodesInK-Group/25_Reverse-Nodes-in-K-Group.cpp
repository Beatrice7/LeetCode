/********************************************************************************** 
* 
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
* 
* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
* 
* You may not alter the values in the nodes, only nodes itself may be changed.
* 
* Only constant memory is allowed.
* 
* For example,
* Given this linked list: 1->2->3->4->5
* 
* For k = 2, you should return: 2->1->4->3->5
* 
* For k = 3, you should return: 3->2->1->4->5
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
	ListNode *reverseBetween(ListNode *prev, ListNode *end, int k) {
		ListNode* begin = prev->next;
		ListNode* cur = begin->next;
		
		for (int i = 1; i < k; ++i){
			begin->next = cur->next;
			cur->next = prev->next;
			prev->next = cur;
			
			cur = begin->next;
		}
		return prev;

	}

	ListNode* reverseKGroup(ListNode* head, int k){
	    if(head == nullptr || head->next == nullptr || k<2) return head;
	    
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *end = head;
		for (int i = 1; i < k; ++i){
			end = end->next;
			if(end == nullptr) return head;
		}
		for (ListNode* prev = &dummy, *begin = prev->next; end && begin;){
			reverseBetween(prev, end, k);
			prev = begin;
			end = prev;
			begin = prev->next;
			for (int i = 0; i < k; ++i){
				end = end ? end->next : nullptr;
			}
		}
		return dummy.next;
	}

};
