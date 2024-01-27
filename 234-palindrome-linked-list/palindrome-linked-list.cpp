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
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* front= temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* rev=reverse(slow->next);
        ListNode* start=head;
        while(rev!=nullptr){
            if(rev->val!=start->val){
                return false;
            }
            rev=rev->next;
            start=start->next;
        }
        return true;
    }
};