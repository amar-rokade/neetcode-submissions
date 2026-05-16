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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= l1;
        int carry = 0;
        int digit;
        int sum;
        ListNode* pl1 = l1;
        while(l1!= NULL &&l2 !=NULL){
            sum = (l1->val + l2->val)+ carry;
            digit = sum % 10;
            carry = sum / 10; 
            l1->val = digit;
            pl1= l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 != NULL && carry != 0){

            while(l1!= NULL && carry!= 0){
                sum =  l1->val + carry;
                digit = sum % 10;
                carry = sum / 10; 
                pl1 = l1;
                l1->val = digit;
                l1 = l1->next;
            }
        }
        else if(l2 != NULL){ //when l2 length is more
            pl1->next= l2; //link l1 to l2

            while(l2!= NULL && carry!= 0){
                sum =  l2->val + carry;
                digit = sum % 10;
                carry = sum / 10; 
                l2->val = digit;
                pl1 = l2;
                l2 = l2->next;
            }

        }

        if(carry != 0){
            ListNode *carryNode = new ListNode(carry);
            pl1->next = carryNode;

        }

        return head;
        
    }
};
