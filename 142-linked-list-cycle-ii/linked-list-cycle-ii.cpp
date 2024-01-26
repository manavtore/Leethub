/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* fast=head;
        ListNode* slow=head;
        int cnt=1;
        
        while(fast!=nullptr && fast->next!=nullptr){        
            fast=fast->next->next;
            slow=slow->next;
            cnt++;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
            
            
        }
        return NULL;
    }
};