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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int,ListNode*> mp;
        mp[0]=dummy;
        int prefsum=0;

        while(head!=nullptr){
            prefsum +=head->val;
            if(mp.find(prefsum)!=mp.end()){
                ListNode* start = mp[prefsum];
                int pf = prefsum;
                ListNode* temp = start;
                while(temp->next!=head){
                    temp=temp->next;
                    pf=pf + temp->val;
                    mp.erase(pf);
                }
                start->next = head->next;
            }else{
                mp[prefsum]=head;
            }
            head=head->next;

        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;

    }
};