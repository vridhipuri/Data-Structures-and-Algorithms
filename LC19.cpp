//19. Remove Nth Node From End of List
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
        ListNode* temp = head;
        int count = 0;
        
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
        if (n == count) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        temp = head;
        int curr = 0;
        ListNode* prev = nullptr;
        
        while (curr != count - n) {
            prev = temp;
            curr++;
            temp = temp->next;
        }
        
        if (prev != nullptr) {
            prev->next = temp->next;
            delete temp;
        }
        
        return head;
    }
};