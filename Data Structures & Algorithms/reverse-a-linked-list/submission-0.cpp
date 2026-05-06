class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *next; 
        ListNode *pre = NULL; 
        
        while(head != NULL){  
            next = head->next;//its for not lost next element as in next step we are updating head->next
            head->next = pre; 
            pre = head;
            head = next;
        }
        return pre; 
    }
};