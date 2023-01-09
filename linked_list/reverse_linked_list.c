#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *new_head = NULL;

    while (head != NULL) {
        struct ListNode *prev_next = head->next;
        head->next = new_head;
        new_head = head;
        head = prev_next;
    }
    return new_head;
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
    list_head = reverseList(list_head);

    // after
    show_list(list_head);

    return 0;
}
