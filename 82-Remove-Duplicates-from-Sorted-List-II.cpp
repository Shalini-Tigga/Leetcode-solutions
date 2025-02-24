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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || head->next==NULL) return head;
        ListNode* node = new ListNode(-1);
        ListNode* res = node;
        ListNode* temp = head;
        while(temp){
            int ct = 0;
            while(temp->next != NULL && temp->val == temp->next->val){
                temp = temp->next;
                ct++;
            }
            if(ct==0){
                node->next = temp;
                node = node->next;
            }
            temp = temp->next;
        }
        node->next = NULL;
        return res->next;
    }
};
