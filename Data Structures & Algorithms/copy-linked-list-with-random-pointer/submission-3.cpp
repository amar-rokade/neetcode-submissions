class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node dummy(0); 
        Node* head2 = &dummy;

        while(head != NULL){
            Node *temp = NULL;  // for main 

            const auto it = mp.find(head);
            if(it != mp.end()){
                temp = it->second;
            }else{
                temp = new Node(head->val);
                mp[head] = temp; 
            }
            head2->next = temp;  

            // FIXED: Handle random safely
            if(head->random != NULL) {
                Node *temp2 = NULL;
                const auto it1 = mp.find(head->random);
                if(it1 != mp.end()){
                    temp2 = it1->second;
                }else{
                    temp2 = new Node(head->random->val);
                    mp[head->random] = temp2;
                }
                temp->random = temp2; 
            } else {
                temp->random = NULL; 
            }
            head = head->next;
            head2 = temp; 
        }

        return dummy.next;
    }
};