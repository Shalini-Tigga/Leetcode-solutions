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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);
        ListNode* point = dummy;
        int count = 0 ;
        while( curr != nullptr){
            if(curr->val != 0){
                count += curr->val;
            }else{
                point->next = new ListNode(count);
                point = point->next;
                count = 0;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};
