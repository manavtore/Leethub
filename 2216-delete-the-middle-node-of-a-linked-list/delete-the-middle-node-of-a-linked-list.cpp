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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr){
            return nullptr;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        int cnt=0;
        while(fast!=nullptr){
            cnt++;
            fast=fast->next;
        }
        int half=cnt/2;
        int index=0;
        ListNode* prev=head;
        while(slow!=nullptr){
            if(index==half){
                break;
            }
            index++;
            prev=slow;
           slow=slow->next;
        }
        ListNode* delNode=slow;
        if(prev!=nullptr){
            prev->next=slow->next;
        }else{
            head=slow->next;
        }
        delete(delNode);
        return head;

    }
};