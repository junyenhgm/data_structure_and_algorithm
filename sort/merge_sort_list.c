#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *list_get_mid(struct ListNode *head)
{
    struct ListNode *fast = head->next;
    struct ListNode *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    struct ListNode *mid = slow->next;
    slow->next = NULL;  // Break the list.
    return mid;
}

struct ListNode *merge_list(struct ListNode *left, struct ListNode *right)
{
    struct ListNode dummy;
    struct ListNode *ptr = &dummy;

    while (left != NULL && right != NULL) {
        if (left->val <= right->val) {
            // Insert left one
            ptr->next = left;
            left = left->next;
        } else {
            // insert right to the list
            ptr->next = right;
            right = right->next;
        }
        ptr = ptr->next;
    }

    if (left) {
        ptr->next = left;
    }

    if (right) {
        ptr->next = right;
    }

    return dummy.next;
}

struct ListNode *sortList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *mid = list_get_mid(head);
    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(mid);

    return merge_list(left, right);
}
