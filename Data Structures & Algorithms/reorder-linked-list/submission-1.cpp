/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL)return head;

        ListNode* p = NULL;
        ListNode* n  = NULL;
        
        while( head!= NULL){
            n = head->next; //capturing next before updating so we should not loose;
            head->next = p; //making link to current to previous
            p = head; //update current element as previous
            head = n; //make next element as  current
        }
        return p;
    }

    void merge(ListNode*  head, ListNode*  head2){
        while(head2 != NULL){
            ListNode* next1 = head->next;
            ListNode* next2 = head2->next; //savwe next elemt before update
            

            head->next  = head2; //update next element
            head2->next = next1;
        //    cout<<"head "<<head->val;
        //    cout<<"head->next "<<head->next->val;

           head = next1;
           head2 = next2;
        }
    }
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* head2 = NULL;

        // #get the middle 
        while(fast!= NULL && fast->next != NULL){
            // cout<<"slow "<<slow->val<<endl;
            // cout<<"fast "<<fast->val<<endl;
            slow = slow->next;
            fast = fast->next->next;
        }

        head2 = slow->next;
        slow->next = NULL;

        // cout<<"mid "<<head2->val<<endl;

        head2 = reverse(head2);
        // cout<<head2->val<<endl;

        merge(head, head2);

    }
};
