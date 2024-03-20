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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        int cnt1=0;
        while(cnt1!=a-1){
            temp1=temp1->next;
            cnt1++;
        }
        
        ListNode* temp2=temp1;
        int cnt2=cnt1;
         while(cnt2!=b){
            temp2=temp2->next;
            cnt2++;
        }
      
        temp2=temp2->next;

        temp1->next = list2;
        ListNode* temp3=list2;
        while(temp3->next!=nullptr){
            temp3=temp3->next;
        }
        temp3->next = temp2;

        return list1;
    }
};