/*You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* curr = &dummy;
    dummy.next = NULL;

    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if(l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;

        carry = sum / 10;
        curr->next = node;
        curr = node;
    }

    return dummy.next;
}
