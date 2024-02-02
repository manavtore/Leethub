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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
        return head;
       }
        ListNode* temp=head;
        int cnt=1;
        while(temp->next!=NULL){
            cnt++;
            temp=temp->next;
        }
        k=k%cnt;
        if (k == 0) {
        return head; 
          }
        temp=head;
        int current=cnt-k-1;
        while(current>0){
           temp=temp->next;
           current--;
        }
        ListNode* newhead=temp->next;
        temp->next=NULL;
        temp=newhead;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        
        return newhead;
    }
};