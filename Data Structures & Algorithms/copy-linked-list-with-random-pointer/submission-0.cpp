/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> oldToNewMap;
        oldToNewMap[nullptr]=nullptr;
        Node* curr = head;
        while(curr!=nullptr){
            Node* copy = new Node(curr->val);
            oldToNewMap[curr]=copy;
            curr=curr->next;
        } 
        curr = head;
        while(curr!=nullptr){
            Node* copy = oldToNewMap[curr];
            copy->next = oldToNewMap[curr->next];
            copy->random= oldToNewMap[curr->random];
            curr=curr->next;
        }
        return oldToNewMap[head];
        
    }
};
