class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. Create the dummy node
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        
        // 2. Advance 'fast' exactly n + 1 steps to create the gap
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // 3. Move both pointers until 'fast' hits the end
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // 4. 'slow' is now resting on the node right BEFORE the target.
        // We can safely bypass the target node.
        slow->next = slow->next->next;
        
        // 5. Return the true start of the list
        return dummy.next;
    }
};