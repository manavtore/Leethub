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
    ListNode* findkthNode(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* rev(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevlast=NULL;
        while(temp!=NULL){
          ListNode* kthNode=findkthNode(temp,k);
          if(kthNode==NULL){
              if(prevlast){
                  prevlast->next=temp;
              }

              break;
          }
        ListNode* nextNode=kthNode->next;
              kthNode->next=NULL;
              rev(temp);
              if(temp==head){
                  head=kthNode;
              }else{
                  prevlast->next=kthNode;
              }
              prevlast=temp;
              
              temp=nextNode;
        }
        return head;
    }
};