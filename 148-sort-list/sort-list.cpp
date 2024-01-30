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
    ListNode* Merge(ListNode* right,ListNode* left){
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        while(right!=nullptr && left!=nullptr){
            if(right->val<left->val){
                temp->next=right;
                temp=right;
                right=right->next;
            }else{
                temp->next=left;
                temp=left;
                left=left->next;
            }
        }
         if(right){
                temp->next=right;
            }else{
                temp->next=left;
            }

         ListNode* result = dummyNode->next;
         delete dummyNode;  

    return result;
    }
    ListNode* sortList(ListNode* head) {
         if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* mid=findMiddle(head);
        ListNode* right=mid->next;
        mid->next=nullptr;
        ListNode* left=head;

        right=sortList(right);
        left=sortList(left);

        return Merge(right,left);

    }
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};