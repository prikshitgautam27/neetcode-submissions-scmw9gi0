class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* second = head; // fast pointer
        ListNode* first = head;  // slow pointer

        // 1. Move 'second' ahead by n steps
        while (n > 0 && second != nullptr) {
            second = second->next;
            n--;
        }

        // 2. If 'second' is null, we reached the end. 
        // If n is 0, it means the Nth node from end is the head.
        if (second == nullptr) {
            if (n == 0) {
                ListNode* temp = head;
                head = head->next;
                delete temp; // Important in C++ to free memory
                return head;
            }
            return head; // n was larger than list length
        }

        // 3. Move both until 'second' reaches the LAST node (not nullptr)
        // This stops 'first' exactly BEFORE the node to be deleted.
        while (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        // 4. Delete the node
        ListNode* nodeToDelete = first->next;
        first->next = first->next->next;
        delete nodeToDelete;

        return head;
    }
};
