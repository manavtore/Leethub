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
        ListNode* curr = head;
        while(curr!=nullptr){
            int newValue = curr->val * 2;
            if(newValue<10){
                curr->val = newValue;
            }else{
                curr ->val = newValue%10;
                if(curr==head){
                    ListNode* newNode = new ListNode(1);
                    head = newNode;
                    head ->next = curr;
                }
            }
            if(curr->next!=nullptr && curr->next->val*2>=10){
                curr->val+=1;
            }

            curr  = curr->next;
        }
        return head;
    }
};