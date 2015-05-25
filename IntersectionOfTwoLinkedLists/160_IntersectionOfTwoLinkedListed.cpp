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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int lenA = 0;
        int lenB = 0;
        while(p1){
            lenA++;
            p1 = p1->next;
        }
        while(p2){
            lenB++;
            p2 = p2->next;
        }
        p1 = headA;
        p2 = headB;
        //let p1 point to the longest list
        if(lenA < lenB){
            swap(p1, p2);
        }
        for(int i = 0; i < abs(lenA - lenB); ++i){
            p1 = p1->next;
        }
        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return (p2 == nullptr ? NULL : p2);
    }
};
