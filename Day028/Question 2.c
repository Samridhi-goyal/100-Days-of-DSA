//Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

#include <stdbool.h>

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while(head) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return true;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* second = reverse(slow);

    struct ListNode* first = head;
    while(second) {
        if(first->val != second->val) return false;
        first = first->next;
        second = second->next;
    }

    return true;
}
