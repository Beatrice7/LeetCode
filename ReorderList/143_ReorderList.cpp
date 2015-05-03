// LeetCode, Reorder List
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;

        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // cut at middle

        //reverse
	    ListNode* p2 = reverse(slow);

    	//merge
    	ListNode* p1 = head, *p1next, *p2next;
    	while (p1->next){
    	    p1next = p1->next;
    	    p2next = p2->next;
    	    
    		p1->next = p2;
    		p2->next = p1next;
    		p2 = p2next;
    		p1 = p1next;
    	}
    	p1->next = p2;	
    }


    void reorderList1(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;

        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // cut at middle

        //reverse
	    slow = reverse(slow);

	    //merge
	    ListNode *p1 = head;
	    while (p1->next){
	        ListNode* p1next = p1->next;
		    p1->next = slow;
		    slow = slow->next;
		    p1->next->next = p1next;
		    p1 = p1next;
	    }
	    p1->next = slow;	
    }


    ListNode* reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        //三个指针：prev, curr, next
        ListNode *prev = head;
        for (ListNode *curr = head->next, *next = curr->next; curr;
            prev = curr, curr = next, next = next ? next->next : nullptr) {
                curr->next = prev;
        }
        head->next = nullptr;
        return prev;
    }
};

