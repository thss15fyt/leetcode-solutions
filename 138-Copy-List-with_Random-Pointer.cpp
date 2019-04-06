/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode *p, *q, *chead;
        p = head;
        while(p != NULL) {
            q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            q->random = p->random;
            p = p->next->next;
        }
        chead = head->next;
        q = chead;
        while(q != NULL) {
            if(q->random != NULL)
                q->random = q->random->next;
            if(q->next == NULL)
                break;
            q = q->next->next;
        }
        p = head;
        q = chead;
        while(p != NULL) {
            p->next = q->next;
            if(p->next != NULL)
                q->next = p->next->next;
            p = p->next;
            q = q->next;
        }
        return chead;
    }
};