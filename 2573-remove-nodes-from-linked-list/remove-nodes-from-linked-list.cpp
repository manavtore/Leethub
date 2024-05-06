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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* current = head;
        while(current!=nullptr){
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* rev = reverse(head);
        int maxi = rev->val;
            ListNode* prev = rev ;
            ListNode* front = rev->next;

            while(front!=nullptr){
                if(front->val<maxi){
                    prev -> next = front->next;
                    front = front->next;
                }else{
                    maxi = front->val;
                    prev = front;
                    front = front->next;
                }
            
            }
        
        return reverse(rev);
    }
};