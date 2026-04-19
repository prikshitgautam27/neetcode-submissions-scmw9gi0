class Solution {
public:
    void reorderList(ListNode* head) {
        // 1. Edge Case: Empty, 1, or 2 nodes (no change needed)
        if (!head || !head->next || !head->next->next) return;

        // 2. Find the Middle using Fast/Slow pointers
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 3. Reverse the Second Half
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; // Detach the first half
        
        ListNode* prev = nullptr;
        ListNode* curr = secondHalf;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        // 'prev' is now the head of the reversed second half

        // 4. Merge the Two Lists
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            
            first->next = second;
            second->next = tmp1;
            
            first = tmp1;
            second = tmp2;
        }
    }
};
