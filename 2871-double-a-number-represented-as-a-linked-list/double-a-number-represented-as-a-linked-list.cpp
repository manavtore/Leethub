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
    ListNode* doubleIt(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            int value = curr->val*2;
            if(value<10){
               curr->val = value;
            }else{
                curr->val = value%10;
                if(prev==nullptr){
                     ListNode* newNode = new ListNode(1);
                    head = newNode;
                    head -> next = curr;
                }else{
                    prev->val+= 1;
                }    
            }
            prev = curr ;
                curr = curr->next;
        }
        return head;
    }
};