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
        ListNode* dummy = new ListNode(0, head);
        ListNode* left=dummy;
        ListNode* right=head;
        while(n){
            right=right->next;
            n--;
        }
        while(right!=nullptr){
            left=left->next;
            right=right->next;
        }
        ListNode* rem = left->next;
        left->next=rem->next;
        delete rem;
        return dummy->next;
    }
};
