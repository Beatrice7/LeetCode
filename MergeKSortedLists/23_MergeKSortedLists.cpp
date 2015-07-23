/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//LeetCode, Merge k Sorted Lists
class Solution {
public:
	//TimeLimitExceeded
	ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        int n = lists.size();
        while(n > 1){
            int k = (n+1)/2;
            for(int i = 0; i < n/2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }

    //AC
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        int n = lists.size();
        //k & k+i
        while(n > 1){
            int k = (n+1)/2;
            for(int i = 0; i < n/2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }

    // Merge Two Sorted Lists
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(-1);
        for (ListNode* p = &head; l1 != nullptr || l2 != nullptr; p = p->next) {
            int val1 = l1 == nullptr ? INT_MAX : l1->val;
            int val2 = l2 == nullptr ? INT_MAX : l2->val;
            if (val1 <= val2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }
        return head.next;
    }
};
