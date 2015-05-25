#include <iostream>
#include <utility>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
	ListNode* p1 = headA;
	ListNode* p2 = headB;
	return nullptr;
}

void printlist(ListNode* head){
	while(head){
		cout << head->val << endl;
        head = head->next;
	}
}

int main(){
	ListNode *A = new ListNode(0);
	ListNode *B = new ListNode(1);
	ListNode *C = new ListNode(2);
	ListNode *D = new ListNode(3);
	ListNode *E = new ListNode(4);
	ListNode *F = new ListNode(5);

	A->next = B;
	B->next = C;
	C->next = NULL;

	D->next = E;
	E->next = F;
	F->next = NULL;

	ListNode* p1 = A;
	ListNode* p2 = D;
	printlist(p1);
	cout << endl;
	printlist(p2);
	swap(p1, p2);
	cout << "after swap" << endl;
	printlist(p1);
	cout << endl;
	printlist(p2);


	
}
