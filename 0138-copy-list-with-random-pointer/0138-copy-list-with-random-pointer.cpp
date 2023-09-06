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
    if(!head)
        return NULL;
    
    // Create a mapping between original nodes and their corresponding new nodes
    std::map<Node*, Node*> mp;
    Node* curr = head;
    Node* prev = NULL;
    Node* newHead = NULL;
    
    // Copy the linked list while creating new nodes and updating the mapping
    while(curr) {
        Node* temp = new Node(curr->val); // Create a new node with the same value as the original
        mp[curr] = temp; // Map the original node to its new copy
        
        // Connect the new node to the copied linked list
        if(newHead == NULL) {
            newHead = temp;
            prev = newHead;
        } else {
            prev->next = temp;
            prev = temp;
        }
        curr = curr->next;
    }
    
    // Traverse the original list again and update the 'random' pointers in the new list
    curr = head;
    Node* newCurr = newHead;
    while(curr) {
        if(curr->random == NULL) {
            newCurr->random = NULL;
        } else {
            newCurr->random = mp[curr->random]; // Map the random pointer to its new copy
        }
        
        newCurr = newCurr->next;
        curr = curr->next;
    }
    
    return newHead; // Return the new head of the copied linked list
}
};