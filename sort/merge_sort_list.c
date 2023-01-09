#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *list_get_mid_next(struct ListNode *head)
{
    struct ListNode *fast = head->next;
    struct ListNode *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    struct ListNode *mid_next = slow->next;
    slow->next = NULL;  // Break the list.
    return mid_next;
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

// Time O(NlogN)
// Space O(LogN)
struct ListNode *sort_list(struct ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    /* Split the list */
    struct ListNode *mid_next = list_get_mid_next(head);
    struct ListNode *left = sort_list(head);
    struct ListNode *right = sort_list(mid_next);

    return merge_list(left, right);
}

void show_list(struct ListNode *head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main(void)
{
    // Get list
    struct ListNode node_0 = {.val = 10, .next = NULL};
    struct ListNode node_1 = {.val = 80, .next = NULL};
    struct ListNode node_2 = {.val = 50, .next = NULL};
    struct ListNode node_3 = {.val = 20, .next = NULL};
    struct ListNode node_4 = {.val = 40, .next = NULL};
    struct ListNode node_5 = {.val = 30, .next = NULL};

    node_0.next = &node_1;
    node_1.next = &node_2;
    node_2.next = &node_3;
    node_3.next = &node_4;
    node_4.next = &node_5;

    struct ListNode *list_head = &node_0;

    // before
    show_list(list_head);

    // sort
    sort_list(list_head);

    // after
    show_list(list_head);

    return 0;
}
