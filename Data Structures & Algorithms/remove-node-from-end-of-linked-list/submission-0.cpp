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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        ListNode* curr=head;
        int count=0;
        while(curr!=nullptr){
            count++;
            curr=curr->next;
        }
        if(n>count) return head;
        if(n==count) {
            ListNode* tmp = head;
            head=tmp->next;
            delete tmp;
            return head;
        }
        curr=head;
        while(count-n-1){
            curr=curr->next;
            count--;
        }
        ListNode* tmp = curr->next;
        curr->next=tmp->next;
        delete tmp;
        
        return head;   
    }
};
