#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL){}
};

void print(RandomListNode*);

RandomListNode* copyRandomList(RandomListNode *head)
{
    int pos = 0;
    map<RandomListNode*, int> node_mapping;
    for(RandomListNode* p = head; p != nullptr; p = p->next, pos++)
    {   
       node_mapping[p] = pos;
    }

    RandomListNode dummy(-1);
    RandomListNode* p = &dummy;

    vector<RandomListNode *> address;

    for(RandomListNode* cur = head; cur != nullptr; cur = cur->next)
    {
        RandomListNode* node = new RandomListNode(cur->label);
        address.push_back(node);
        p->next = node;
        p = p->next;
    }
    
    RandomListNode* p_origin = head;
    for(RandomListNode* p = dummy.next; p != nullptr; p = p->next, p_origin = p_origin->next)
    {
        if(p_origin->random != nullptr){
            int pos = node_mapping[p_origin->random];
            p->random = address[pos];
        }else{
            p->random = nullptr;
        }

    }

    return dummy.next;
}


void print(RandomListNode *p){
    for(RandomListNode* cur = p; cur != nullptr; cur = cur->next){
        cout << cur->label << " ";
    }
    cout <<endl;
}

void print_random(RandomListNode* head){
    cout << "random: ";
    for(RandomListNode* cur = head; cur != nullptr; cur = cur->next){
        cout << cur->random->label << " " ;
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    RandomListNode r1(1);
    RandomListNode r2(2);
    RandomListNode r3(3);

    r1.next = &r2;
    r2.next = &r3;
    r1.random = &r2;
    r2.random = &r1;
    r3.random = &r1;

    print(copyRandomList(&r1));

    return 0;
}




/*
 *  Considering we have a link as below:
 *
 *
 *       +-------------+
 *       |             v
 *    +-------+    +-------+    +-------+
 *    | node1 |----> node2 |----> node3 |--->NULL
 *    +-------+    +-------+    +-------+
 *      ^  ^           |           |
 *      |  +-----------+           |
 *      +--------------------------+
 * 
 *  1) Using a map to store each node's random pointer's position
 *
 *      map[node1->random] = 1;
 *      map[node2->random] = 0;
 *      map[node3->random] = 0;
 *
 *  2) Clone the linked list (only consider the next pointer)
 *
 *      new1 --> new2 --> new3 --> NULL 
 *
 *  3) Using an array to strore the order of the cloned linked-list
 *
 *      v[0] = &new1
 *      v[1] = &new2
 *      v[2] = &new3
 * 
 *  4) Then we can clone the random pointers.
 *
 *      new->random = v [ map[node->random] ]
 *
 */
