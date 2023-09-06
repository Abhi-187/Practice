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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        // Initialize a pointer 'curr' to the dummy head node
        ListNode* curr = dummyHead;
        // Initialize a carry variable to handle overflow
        int carry = 0;
        // Continue looping until both input lists are empty and there's no carry left
        while (l1 != NULL || l2 != NULL || carry != 0) {
            // Get the values of the current nodes in the input lists (default to 0 if NULL)
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            // Calculate the sum of the current digits and the carry from the previous iteration
            int sum = carry + x + y;
            // Calculate the new carry for the next iteration
            carry = sum / 10;
            // Create a new node with the least significant digit of 'sum' and attach it to 'curr'
            curr->next = new ListNode(sum % 10);
            // Move 'curr' to the newly created node
            curr = curr->next;       
            // Move to the next nodes in the input lists (or set to nullptr if already at the end)
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;        
    }
};