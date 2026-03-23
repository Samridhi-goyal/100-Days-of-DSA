/*Given the head of a singly linked list, the task is to remove a cycle if present. 
  A cycle exists when a node's next pointer points back to a previous node, forming a loop.
  Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. 
  The terminal will print true if a cycle is removed otherwise, it will print false*/

class Solution {
public:
    int removeLoop(struct Node* head)
    {
        struct Node *slow = head, *fast = head;

        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                slow = head;

                if (slow == fast)
                {
                    while (fast->next != slow)
                        fast = fast->next;
                }
                else
                {
                    while (slow->next != fast->next)
                    {
                        slow = slow->next;
                        fast = fast->next;
                    }
                }

                fast->next = NULL;
                return 1;
            }
        }

        return 0;
    }
};
