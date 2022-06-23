/*

ref:
http://www.ted.com/talks/linus_torvalds_the_mind_behind_linux?language=zh-tw
https://hackmd.io/@sysprog/c-linked-list
https://github.com/mkirchner/linked-list-good-taste

Good task linked list

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val){
    /* use a pointer to the entry pointer, and initialize that with the address of the list head. */
    struct ListNode **indirect = &head;
    
    while ((*indirect) != NULL) {
        
        /* remove the node just let current *indirect = target->next */
        if ((*indirect)->val == val) {
            /* Change content of  current node via dereferencing address the next node */
            *indirect = (*indirect)->next;
        } else {
            /* Let indirect be the address of the next node */
            indirect = &(*indirect)->next;
        }

    }
    
    return head;
}
