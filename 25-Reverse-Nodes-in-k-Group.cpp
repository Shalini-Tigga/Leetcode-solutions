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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head; 
        }
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* future = nullptr;
        int count = 0; 
        while(curr != nullptr){
            count++;
            curr = curr->next;
        }
        curr = head;
        while(count >= k){
            ListNode *tail = curr;
            for (int i = 0; i < k; i++) {
                future = curr->next;
                curr->next = prev->next;
                prev->next = curr;
                curr = future;
            }
            tail->next = curr;
            prev = tail;
            count -= k;
        }
        return dummy->next;
    }
};
