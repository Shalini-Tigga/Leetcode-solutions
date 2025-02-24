/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        bool check = false;
        while(fast!= nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                check = true;
                break;
            }
        }
        if (!check){
            return nullptr;
        }
        ListNode * temp = head;
        while(temp!= slow){
            temp = temp->next;
            slow = slow->next;
        }
        return temp;
    }
};
